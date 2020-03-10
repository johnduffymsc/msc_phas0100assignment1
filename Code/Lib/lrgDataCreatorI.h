/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Linear Regression

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef lrgDataCreatorI_h
#define lrgDataCreatorI_h

#include "lrgBasicTypes.h"


namespace lrg {

  class DataCreatorI {
  public:
    virtual vector_of_pairs GetData() = 0;
  };

} // end namespace

#endif
