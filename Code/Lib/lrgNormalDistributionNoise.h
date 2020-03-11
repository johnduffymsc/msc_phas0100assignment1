/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Linear Regression

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef lrgNormalDistributionNoise_h
#define lrgNormalDistributionNoise_h

#include "lrgNoiseGeneratorI.h"

#include <random>


namespace lrg {

  class NormalDistributionNoise : public NoiseGeneratorI {
  public:
    NormalDistributionNoise(const double mean, const double sigma);
    ~NormalDistributionNoise();
    double GetNumber();
  private:
    std::default_random_engine generator_;
    std::normal_distribution<double> noise_;
  };

} // end namespace

#endif
