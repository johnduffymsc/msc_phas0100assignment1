/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Linear Regression

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "lrgLinearDataCreator.h"

#include <vector>
#include <random>

namespace lrg {

  // LinearDataCreator::GetData()
  
  std::vector<std::pair<double, double>> LinearDataCreator::GetData() {

    // Create the vector to be returned from this function.

    std::vector<std::pair<double, double>> data(10);

    // Create a random noise generator from the normal distribution.
    
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(1.0, 0.0);

    // Generate the data.

    for (int i = 0; i < data.size(); ++i) {
      data[i].first = i;
      data[i].second = i;
    }
    
    // Return the vector.

    return data;

  }

  // Overloaded LinearDataCreator::GetData(const int n)
  
  std::vector<std::pair<double, double>> LinearDataCreator::GetData(const int n) {

    // Create the vector to be returned from this function.

    std::vector<std::pair<double, double>> data(n);

    // Create a random noise generator from the normal distribution.
    
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(1.0, 0.0);

    // Generate the data.

    for (int i = 0; i < data.size(); ++i) {
      data[i].first = i;
      data[i].second = i;
    }

    // Return the vector.

    return data;

  }

} // end namespace
