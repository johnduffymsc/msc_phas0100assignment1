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
#include "lrgMyFunctions.h"
#include <iostream>
#include <vector>

TEST_CASE( "My first test", "[some group identifier]" ) {
  int a = 5;
  REQUIRE( a < 6 );
}

TEST_CASE( "My second test", "[some group identifier]" ) {
  std::vector<int> a;
  REQUIRE( a.size() == 0 );
}

TEST_CASE( "Simple add", "[MyFirstAddFunction]") {
  REQUIRE( lrg::MyFirstAddFunction(1, 2) == 3);
}
