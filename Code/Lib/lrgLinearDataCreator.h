/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Linear Regression

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef lrgLinearDataCreator_h
#define lrgLinearDataCreator_h

#include "lrgDataCreatorI.h"

#include <memory>
#include <random>


namespace lrg {

  class NoiseGenerator {
  public:
    NoiseGenerator(const double mean, const double sigma);
    ~NoiseGenerator();
    double GetNumber();
  private:
    std::default_random_engine generator_;
    std::normal_distribution<double> noise_;
  };

  class LinearDataCreator : public DataCreatorI {
  public:
    LinearDataCreator(const double theta0, const double theta1, NoiseGenerator *noise_generator_ptr);
    ~LinearDataCreator();
    vector_of_pairs GetData();
    vector_of_pairs GetData(const int n);
  private:
    const double theta0_;
    const double theta1_;
    // LinearDataCreator HAS-A NoiseGenerator with externally configured parameters.
    NoiseGenerator *noise_generator_;
  };

} // end namespace

#endif
