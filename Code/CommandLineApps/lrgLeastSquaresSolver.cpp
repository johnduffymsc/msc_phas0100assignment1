/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Linear Regression

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <lrgExceptionMacro.h>
#include <lrgLinearDataCreator.h>
#include <lrgNormalDistributionNoise.h>
#include <lrgFileLoaderDataCreator.h>
#include <lrgNormalEquationSolverStrategy.h>
#include <lrgGradientDescentSolverStrategy.h>

#include <CLI/CLI.hpp>

#include <iostream>


int main(int argc, char** argv)
{

  //
  // Parse the command line arguments.
  //
  
  CLI::App app{"A program to perform Linear Regression."};

  std::string file = "";
  CLI::Option *file_option = app.add_option("-f,--file", file, "Data file, space delimited x and y pairs, one pair per line.");
  file_option->check(CLI::ExistingFile);

  std::array<double, 4> rand {0.0, 1.0, 0.0, 1.0};
  CLI::Option *rand_option = app.add_option("-r,--rand", rand, "Random data generation [theta0, theta1, noise_mean, noise_sigma].");


  /*
  bool fake = false;
  CLI::Option *fake_option = app.add_option("--fake", fake, "Generate fake data.");

  double fake_mean = 0.0;
  CLI::Option *fake_mean_option = app.add_option("--fake_mean", fake_mean, "Fake noise mean.");
  
  double fake_sigma = 1.0;
  CLI::Option *fake_sigma_option = app.add_option("--fake_sigma", fake_sigma, "Fake noise standard deviation.");

  double fake_theta0 = 0.0;
  CLI::Option *fake_theta0_option = app.add_option("--fake_theta0", fake_theta0, "Fake theta0.");
  
  double fake_theta1 = 1.0;
  CLI::Option *fake_theta1_option = app.add_option("--fake_theta1", fake_theta1, "Fake theta1.");
  
  fake_option->needs(fake_mean_option);
  fake_option->needs(fake_sigma_option);
  fake_option->needs(fake_theta0_option);
  fake_option->needs(fake_theta1_option);
  */
  
  file_option->excludes(rand_option);

  

  std::string solver = "";
  CLI::Option *solver_option = app.add_option("-s,--solver", solver, "Solver to perform linear regression.");
  solver_option->check(CLI::IsMember({"normal_equations", "gradient_descent"}));
  solver_option->required();
  
  CLI11_PARSE(app, argc, argv);

  // At this point we are guaranteed that:
  //
  // 1. filename_option is either (a) "", or (b) "filename_of_a_file_that_exists"
  //
  // 2. solver_option is either "normal_equations" or "gradient_descent"
  //
  // Let's continue on this basis.

  
  //
  // Get the data.
  //

  lrg::vector_of_pairs data;

  if (file == "") {
    // Noise generator.
    lrg::NormalDistributionNoise noise(rand[2], rand[3]);
    // Linear data creator.
    lrg::LinearDataCreator creator(rand[0], rand[1], noise);
    data = creator.GetData();
  }
  else {
    // Read data from a file wrapping IO operations in a try block.
    try {
      lrg::FileLoaderDataCreator creator(file);
      data = creator.GetData();
    }
    catch (lrg::Exception& e) {
      std::cerr << "Caught lrg::Exception: " << e.GetDescription() << std::endl;
    // TODO: return EXIT_FAILURE
    }
    catch (std::exception& e) {
      std::cerr << "Caught std::exception: " << e.what() << std::endl;
    // TODO: return EXIT_FAILURE
    }
  }
  

  //
  // Linear regression.
  //

  lrg::single_pair theta;

  if (solver == "normal_equations") {
    // Normal Equations Solver.
    lrg::NormalEquationSolverStrategy solver_strategy;
    theta = solver_strategy.FitData(data);
  }
  else {
    // Gradient Descent Solver.
    // TODO: Parameterise the below...
    const lrg::single_pair theta_zero (5.0, 5.0);
    const int max_iterations = 1000;
    const double eta = 0.1;
    lrg::GradientDescentSolverStrategy solver_strategy(theta_zero, max_iterations, eta);
    theta = solver_strategy.FitData(data);
  }
  

  //
  // Print result.
  //

  std::cout << "theta0: " << theta.first << std::endl;
  std::cout << "theta1: " << theta.second << std::endl;

  // Produce Gnuplot script.
  
  try {
    std::fstream f ("lrgLeastSquaresSolver.plt", std::fstream::out);
    f << "set title " << "'Linear Regression" << std::endl;
    f << "set terminal png size 1920,1080" << std::endl;
    f << "set output " << "'lrgLeastSquaresSolver.png'" << std::endl; 
    f << "set grid" << std::endl;
    f << "set xlabel 'x'" << std::endl;
    f << "set ylabel 'y'" << std::endl;
    f << "f(x) = theta0 + theta1 * x" << std::endl;
    f << "theta0 = " << theta.first << std::endl;
    f << "theta1 = " << theta.second << std::endl;
    f << "plot '-' using 1:2 with points title 'Data', f(x) with lines title 'Regression Line'" << std::endl;
    for (auto p : data) {
      f  << p.first << " " << p.second << std::endl;
    }
    f << "e" << std::endl;
  }
  catch (lrg::Exception& e) {
    std::cerr << "Caught lrg::Exception: " << e.GetDescription() << std::endl;
    // TODO: return EXIT_FAILURE
  }
  catch (std::exception& e) {
    std::cerr << "Caught std::exception: " << e.what() << std::endl;
    // TODO: return EXIT_FAILURE
  }


  //
  // Success!
  //

  return EXIT_SUCCESS;
}
