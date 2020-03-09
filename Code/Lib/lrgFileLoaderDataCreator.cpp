/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Linear Regression

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "lrgFileLoaderDataCreator.h"

#include <fstream>
#include <string>
#include <vector>


namespace lrg {

  FileLoaderDataCreator::FileLoaderDataCreator() {};
  
  FileLoaderDataCreator::FileLoaderDataCreator(const std::string filename) : filename_(filename) {};
  
  FileLoaderDataCreator::~FileLoaderDataCreator() {};
  
  std::vector<std::pair<double, double>> FileLoaderDataCreator::GetData()
  {
    std::vector<std::pair<double, double>> v;
    std::pair<double, double> p;

    try {
      std::fstream f (filename_, std::fstream::in);
      while (f >> p.first >> p.second) {
	v.push_back(p);
      }
    } catch (std::exception e) {
      // Catch and re-throw all exceptions. Let the caller decide what to do.
      throw e;
    }

    return v;
  }

} // end namespace
