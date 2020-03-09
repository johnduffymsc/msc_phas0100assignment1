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


int main(int argc, char *argv[])
{
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
