/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Linear Regression

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef lrgNormalEquationSolverStrategy_h
#define lrgNormalEquationSolverStrategy_h

#include "lrgLinearModelSolverStrategyI.h"

#include <vector>

namespace lrg
{
  class NormalEquationSolverStrategy : public LinearModelSolverStrategyI {
  public:
    // Constructor.
    NormalEquationSolverStrategy();
    // Destructor.
    ~NormalEquationSolverStrategy();
    // Methods.
    std::pair<double, double> FitData(std::vector<std::pair<double, double>>);
  };

} // end namespace

#endif
