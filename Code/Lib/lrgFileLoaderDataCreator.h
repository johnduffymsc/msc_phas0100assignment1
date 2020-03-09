/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Linear Regression

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef lrgFileLoaderDataCreator_h
#define lrgFileLoaderDataCreator_h

#include "lrgDataCreatorI.h"

#include <string>
#include <vector>


namespace lrg
{
  class FileLoaderDataCreator : public DataCreatorI {
  public:
    FileLoaderDataCreator();
    FileLoaderDataCreator(const std::string filename);
    ~FileLoaderDataCreator();
    std::vector<std::pair<double, double>> GetData();
  private:
    const std::string filename_;
  };

} // end namespace

#endif
