/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Linear Regression

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef lrgLinearModelSolverStrategyI_h
#define lrgLinearModelSolverStrategyI_h

#include "lrgBasicTypes.h"


namespace lrg {

  class LinearModelSolverStrategyI {
  public:
    virtual single_pair FitData(vector_of_pairs) = 0;
  };

} // end namespace

#endif
