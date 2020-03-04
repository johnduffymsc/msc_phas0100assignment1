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

#include <iostream>


TEST_CASE("Test instantiation of LinearDataCreator with default constructor", "[LinearDataCreator]") {
  lrg::LinearDataCreator LinearDataCreatorInstance;
  REQUIRE(1 == 1);  // TODO(John) Meaningful test of class instantiation.
}


TEST_CASE("Test instantiate of LinearDataCreator", "[LinearDataCreator]") {
  lrg::LinearDataCreator LinearDataCreatorInstance(1.0, 1.0);
  REQUIRE(1 == 1);  // TODO(John) Meaningful test of class instantiation.
}


TEST_CASE("Test GetData()", "[LinearDataCreator]") {
  lrg::LinearDataCreator LinearDataCreatorInstance;  // Default: y = x.
  std::vector<std::pair<double, double>> data = LinearDataCreatorInstance.GetData();  // Default: 10 data points, x = [0, 9]
  REQUIRE(data.size() == 10);
  REQUIRE(data[0] == std::pair<double, double>(0.0, 0.0));
  REQUIRE(data[9] == std::pair<double, double>(9.0, 9.0));
}


//TEST_CASE("Test GetData()", "[LinearDataCreator]") {
//  const double theta0 = 1.0;
//  const double theta1 = 2.0;
//  const int n = 20;
//  lrg::LinearDataCreator LinearDataCreatorInstance(theta0, theta1);
//  std::vector<std::pair<double, double>> data = LinearDataCreatorInstance.GetData(n);
  //REQUIRE(data.size() == n);
  //REQUIRE(data[0] == std::pair<double, double>(0.0, theta0));
  //REQUIRE(data[n - 1] == std::pair<double, double>(n - 1, theta0 + theta1 * (n - 1)));
//}
