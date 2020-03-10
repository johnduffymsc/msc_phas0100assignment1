/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Linear Regression

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef lrgGradientDescentSolverStrategy_h
#define lrgGradientDescentSolverStrategy_h

#include "lrgLinearModelSolverStrategyI.h"


namespace lrg {

  class GradientDescentSolverStrategy : public LinearModelSolverStrategyI {
  public:
    GradientDescentSolverStrategy(const single_pair theta_zero, const int max_iterations, const double eta);
    single_pair FitData(vector_of_pairs);
  private:
    const single_pair theta_zero_;
    const int max_iterations_;
    const double eta_;
  };
  
} // end namespace

#endif
