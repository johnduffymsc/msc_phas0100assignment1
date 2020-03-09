/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Linear Regression

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include <lrgExceptionMacro.h>

#include <CLI/CLI.hpp>

#include <iostream>


int main(int argc, char** argv)
{
  CLI::App app{"A program to perform Linear Regression."};

  std::string filename = "";
  CLI::Option *filename_option = app.add_option("-f,--file", filename, "Data file");
  filename_option->check(CLI::ExistingFile);
  filename_option->required();
  
  CLI11_PARSE(app, argc, argv);


  try
  {
    std::cout << "Hello..." << std::endl;
  }
  catch (lrg::Exception& e)
  {
    std::cerr << "Caught lrg::Exception: " << e.GetDescription() << std::endl;
  }
  catch (std::exception& e)
  {
    std::cerr << "Caught std::exception: " << e.what() << std::endl;
  }

  return EXIT_SUCCESS;
}
