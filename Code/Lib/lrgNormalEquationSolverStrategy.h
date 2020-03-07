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
  typedef std::pair<double, double> single_pair;
  typedef std::vector<std::pair<double, double>> vector_of_pairs;
  
  class NormalEquationSolverStrategy : public LinearModelSolverStrategyI {
  public:
    NormalEquationSolverStrategy();
    ~NormalEquationSolverStrategy();
    //std::pair<double, double> FitData(std::vector<std::pair<double, double>>);
    single_pair FitData(vector_of_pairs);
  };

} // end namespace

#endif
