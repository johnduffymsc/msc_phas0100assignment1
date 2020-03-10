/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Linear Regression

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "lrgLinearDataCreator.h"

#include <random>


namespace lrg {

  // Constructors.

  LinearDataCreator::LinearDataCreator() : theta0_(0.0), theta1_(1.0) {};
  
  LinearDataCreator::LinearDataCreator(const double theta0, const double theta1) : theta0_(theta0), theta1_(theta1) {};


  // Destructor.

  LinearDataCreator::~LinearDataCreator() {};
  
  
  // LinearDataCreator::GetData().
  
  vector_of_pairs LinearDataCreator::GetData() {

    // Create the vector to be returned from this function.

    vector_of_pairs  data (10);

    // Create a random noise generator from the normal distribution.
    
    std::default_random_engine generator;
    std::normal_distribution<double> noise(0.0, 1.0);

    // Generate the data.

    for (int x = 0; x < data.size(); ++x) {
      data[x].first = x;
      data[x].second = theta1_ * x + theta0_ + noise(generator);
    }
    
    // Return the vector.

    return data;

  }


  // LinearDataCreator::GetData(const int n).
  
  vector_of_pairs LinearDataCreator::GetData(const int n) {

    // Create the vector to be returned from this function.

    vector_of_pairs data (n);

    // Create a random noise generator from the normal distribution.
    
    std::default_random_engine generator;
    std::normal_distribution<double> noise(0.0, 1.0);

    // Generate the data.

    for (int x = 0; x < data.size(); ++x) {
      data[x].first = x;
      data[x].second = theta1_ * x + theta0_ + noise(generator);
    }
    
    // Return the vector.

    return data;

  }

} // end namespace
