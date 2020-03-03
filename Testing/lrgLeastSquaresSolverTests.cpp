/*=============================================================================

  PHAS0100ASSIGNMENT1: PHAS0100 Assignment 1 Linear Regression

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "catch.hpp"
#include "lrgCatchMain.h"
#include "lrgLinearDataCreator.h"

TEST_CASE("Instantiate concrete LinearDataCreator class.", "[LinearDataCreator]") {
    lrg::LinearDataCreator ldc;
    REQUIRE(1 == 1);  // TODO(John) Meaningful test of class instantiation.
}
