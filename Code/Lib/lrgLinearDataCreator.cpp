/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Linear Regression

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "lrgLinearDataCreator.h"


namespace lrg {

  NoiseGenerator::NoiseGenerator(const double mean, const double sigma)
    : noise_(mean, sigma) {};

  NoiseGenerator::~NoiseGenerator() {};

  double NoiseGenerator::GetNumber() {

    return noise_(generator_);

  };
  
  
  LinearDataCreator::LinearDataCreator(const double theta0, const double theta1, NoiseGenerator *noise_generator_ptr)
    : theta0_(theta0), theta1_(theta1), noise_generator_(noise_generator_ptr) {};

  LinearDataCreator::~LinearDataCreator() {};
  
  vector_of_pairs LinearDataCreator::GetData() {

    vector_of_pairs data(1000);  // TODO(John): Declare 1000 as a constant somewhere.

    for (int x = 0; x < data.size(); ++x) {
      data[x].first = x;
      data[x].second = theta0_ + theta1_ * x + noise_generator_->GetNumber();
    }
    
    return data;

  };

} // end namespace
