/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Linear Regression

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "lrgLinearDataCreator.h"

#include <memory>


namespace lrg {

  LinearDataCreator::LinearDataCreator(const double theta0, const double theta1, NormalDistributionNoise noise)
    : theta0_(theta0), theta1_(theta1), noise_(std::make_unique<NormalDistributionNoise>(noise)) {};

  LinearDataCreator::~LinearDataCreator() {};
  
  vector_of_pairs LinearDataCreator::GetData() {

    vector_of_pairs data(1000);  // TODO(John): Declare 1000 as a constant somewhere.

    for (int x = 0; x < data.size(); ++x) {
      data[x].first = x;
      data[x].second = theta0_ + theta1_ * x + noise_->GetNumber();
    }
    
    return data;

  };

} // end namespace
