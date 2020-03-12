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
#include <vector>


int main(int argc, char** argv)
{

  //
  // Parse the command line arguments.
  //
  
  CLI::App app{"A program to perform Linear Regression."};

  std::string file = "";
  CLI::Option *file_option = app.add_option("-f,--file", file, "Read data from a file, space delimited x and y pairs, one pair per line");
  file_option->check(CLI::ExistingFile);

  std::vector<double> rand {0.0, 1.0, 0.0, 1.0};
  CLI::Option *rand_option = app.add_option("-r,--rand", rand, "Generate random data, e.g. --rand theta0 theta1 noise_mean noise_sigma");
  rand_option->expected(4);

  file_option->excludes(rand_option);
  rand_option->excludes(file_option);

  std::string solver = "";
  CLI::Option *solver_option = app.add_option("-s,--solver", solver, "Solver to perform linear regression");
  solver_option->check(CLI::IsMember({"normal_equations", "gradient_descent"}));
  solver_option->required();
  
  std::vector<double> grad {5.0, 5.0, 1000.0, 0.1};
  CLI::Option *grad_option = app.add_option("-g,--grad", grad, "Gradient Descent parameters, e.g. --grad x0 y0 max_iterations eta");
  grad_option->expected(4);

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
    }
    catch (std::exception& e) {
      std::cerr << "Caught std::exception: " << e.what() << std::endl;
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
    const lrg::single_pair theta_zero (grad[0], grad[1]);
    const int max_iterations = grad[2];
    const double eta = grad[3];
    lrg::GradientDescentSolverStrategy solver_strategy(theta_zero, max_iterations, eta);
    theta = solver_strategy.FitData(data);
  }
  

  //
  // Print result.
  //

  std::cout << std::setprecision (16) << "theta0: " << theta.first << std::endl;
  std::cout << std::setprecision (16) << "theta1: " << theta.second << std::endl;

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
