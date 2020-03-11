/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Linear Regression

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "lrgNormalDistributionNoise.h"

#include <memory>


namespace lrg {

  NormalDistributionNoise::NormalDistributionNoise(const double mean, const double sigma)
    : noise_(mean, sigma) {};

  NormalDistributionNoise::~NormalDistributionNoise() {};

  double NormalDistributionNoise::GetNumber() {

    return noise_(generator_);

  };
  
} // end namespace
