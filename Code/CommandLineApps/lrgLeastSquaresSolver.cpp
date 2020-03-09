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
  
  CLI::App app{"A program to perform Linear Regression."};

  std::string filename = "";
  CLI::Option *filename_option = app.add_option("-f,--file", filename, "Data file, space separated X and y pairs, one pair per line.");
  filename_option->check(CLI::ExistingFile);
  filename_option->required();
  
  std::string solver = "";
  CLI::Option *solver_option = app.add_option("-s,--solver", solver, "Solver to perform linear regression.");
  solver_option->check(CLI::IsMember({"normal_equations", "gradient_descent"}));
  solver_option->required();
  
  CLI11_PARSE(app, argc, argv);


  //
  // Get the data.
  //

  lrg::vector_of_pairs data;
  
  try {
    lrg::FileLoaderDataCreator creator (filename);
    data = creator.GetData();
  }
  catch (lrg::Exception& e) {
    std::cerr << "Caught lrg::Exception: " << e.GetDescription() << std::endl;
  }
  catch (std::exception& e) {
    std::cerr << "Caught std::exception: " << e.what() << std::endl;
  }


  //
  // Linear regression.
  //

  lrg::single_pair theta;
  
  lrg::NormalEquationSolverStrategy solver_strategy;
  theta = solver_strategy.FitData(data);


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
  } catch (...) {
    // TODO(John): Improve below.
    std::cout << "Caught Exception!." << std::endl;
  }


  //
  // Success!
  //

  return EXIT_SUCCESS;
}
