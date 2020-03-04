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

#include <vector>

namespace lrg
{
  class LinearDataCreator : public DataCreatorI {
  public:
    LinearDataCreator();
    LinearDataCreator(const double theta0, const double theta1);
    std::vector<std::pair<double, double>> GetData();
    std::vector<std::pair<double, double>> GetData(const int n);
  private:
    const double theta0_;
    const double theta1_;
  };

} // end namespace

#endif
