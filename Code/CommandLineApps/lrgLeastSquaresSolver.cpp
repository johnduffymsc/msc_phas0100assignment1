/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Linear Regression

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <lrgExceptionMacro.h>
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
  
  CLI::App app{"A command line interface program to perform Linear Regression. Data is supplied from a data file via the --file option, or randomly generated if the --file option is not given. The data file format is a space delimited 'x y' pair, one pair on each line. In the absence of the --file option, linear data is generated with user specified intercept and gradient values, together with the mean and and standard deviation of random noise which is applied to the linear data. The method used to solve the linear regression is one of 'normal_equations' or 'gradient_descent', which is selected via the --solver option. The program returns the intercept and gradient of the linear regression. Additionally, the program generates a Gnuplot script which can be used with Gnuplot to generate a PNG plot of the data and resultant regression line."};

  std::string filename = "";
  CLI::Option *filename_option = app.add_option("-f,--file", filename, "Data file, space separated X and y pairs, one pair per line.");
  filename_option->check(CLI::ExistingFile);
  filename_option->required();
  
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

  if (filename == "") {
    // Generate random data.
    ;
  }
  else {
    // Read data from a file wrapping IO operations in a try block.
    try {
      lrg::FileLoaderDataCreator creator (filename);
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
    ;
  }
  

  //
  // Print result.
  //

  std::cout << "theta0: " << theta.first << std::endl;
  std::cout << "theta1: " << theta.second << std::endl;

  // Produce Gnuplot script.
  
  try {
    std::fstream f ("LeastSquaresSolver.plt", std::fstream::out);
    f << "set title " << "'Linear Regression of " << filename << "'" << std::endl;
    f << "set terminal png size 1920,1080" << std::endl;
    f << "set output " << "'LeastSquaresSolver.png'" << std::endl; 
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
