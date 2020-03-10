/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Linear Regression

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "lrgNormalEquationSolverStrategy.h"

#include "Eigen/Dense"


namespace lrg {

  // Constructor.

  NormalEquationSolverStrategy::NormalEquationSolverStrategy() {};
  

  // Destructor.

  NormalEquationSolverStrategy::~NormalEquationSolverStrategy() {};


  // FitData().
  
  single_pair NormalEquationSolverStrategy::FitData(vector_of_pairs v) {

    // Test vector size >= 2.


    // Test typeid of pair types.


    // Copy the STL vector of pairs input data to an Eigen matrix X and vector y. 

    Eigen::MatrixXd X(v.size(), 2);
    Eigen::VectorXd y(v.size());

    for (auto i = 0; i < v.size(); ++i) {
      X(i, 0) = 1.0;
      X(i, 1) = v[i].first;
      y(i) = v[i].second;
    }


    // Solve the normal equations.

    Eigen::VectorXd theta(2);

    theta = (X.transpose() * X).ldlt().solve(X.transpose() * y);


    // Return theta as an STL pair.

    single_pair p(theta(0), theta(1));

    return p;
    
  };

} // end namespace
