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


namespace lrg {

  //
  // IO Exceptions to be caught and handled by caller.
  //
  
  FileLoaderDataCreator::FileLoaderDataCreator(const std::string& filename)
  {
    file_.open(filename, std::fstream::in);  // RAII      
  };

  
  FileLoaderDataCreator::~FileLoaderDataCreator()
  {
    file_.close();  // RAII
  };

  
  vector_of_pairs FileLoaderDataCreator::GetData()
  {  
    vector_of_pairs v;
    single_pair p;

    while (file_ >> p.first >> p.second) {
      v.push_back(p);
    }

    return v;
  }

} // end namespace
