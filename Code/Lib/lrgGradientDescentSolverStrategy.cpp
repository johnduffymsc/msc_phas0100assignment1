/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Linear Regression

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "lrgGradientDescentSolverStrategy.h"

#include "Eigen/Dense"


namespace lrg {

  GradientDescentSolverStrategy::GradientDescentSolverStrategy(const single_pair theta_zero, const int max_iterations, const double eta) : theta_zero_(theta_zero), max_iterations_(max_iterations), eta_(eta) {}


  single_pair GradientDescentSolverStrategy::FitData(vector_of_pairs v) {

    // Copy the STL vector of pairs input data to an Eigen matrix X and vector y. 
    
    Eigen::MatrixXd X(v.size(), 2);
    Eigen::VectorXd y(v.size());

    for (auto i = 0; i < v.size(); ++i) {

      X(i, 0) = 1.0;
      X(i, 1) = v[i].first;

      y(i) = v[i].second;

    }

    // Solve by Gradient Descent.
    
    Eigen::VectorXd theta(2);
    Eigen::VectorXd gradients(2);

    // Set initial value of theta.

    theta(0) = theta_zero_.first;
    theta(1) = theta_zero_.second;
    
    // Iterate until terminating conditions are reached.
    
    for (auto i = 0; i < max_iterations_; ++i) {

      // Calculate the gradients.

      gradients = 2.0 / v.size() * X.transpose() * (X * theta - y);

      // Finite Difference scheme.

      theta = theta - eta_ * gradients;

    }
    
    // Return theta as an STL pair.

    single_pair p (theta(0), theta(1));

    return p;
    
  }

} // end namespace
