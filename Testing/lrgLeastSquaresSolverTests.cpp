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
#include "lrgFileLoaderDataCreator.h"
#include "lrgNormalEquationSolverStrategy.h"

#include <fstream>
#include <iostream>
#include <typeinfo>


//
// Linear Data Creator Tests.
//

// Test the default constructor does actually construct an object of the correct type.

TEST_CASE("Test LinearDataCreator default constructor", "[LinearDataCreator]") {
  lrg::LinearDataCreator LinearDataCreatorInstance;
  REQUIRE(typeid(LinearDataCreatorInstance) == typeid(lrg::LinearDataCreator));
}


// Test the non-default constructor does actually construct an object of the correct type.

TEST_CASE("Test LinearDataCreator non-default constructor", "[LinearDataCreator]") {
  lrg::LinearDataCreator LinearDataCreatorInstance(1.0, 1.0);
  REQUIRE(typeid(LinearDataCreatorInstance) == typeid(lrg::LinearDataCreator));
}


// Test the LinearDataCreator default constructor and GetData() method.

TEST_CASE("Test GetData(): Default y = x, for x in [0, 9]", "[LinearDataCreator]") {
  lrg::LinearDataCreator LinearDataCreatorInstance;
  lrg::vector_of_pairs data = LinearDataCreatorInstance.GetData();
  REQUIRE(data.size() == 10);
  //REQUIRE(data[0] == std::pair<double, double>(0.0, 0.0));
  //REQUIRE(data[9] == std::pair<double, double>(9.0, 9.0));
}


// Test the LinearDataCreator non-default constructor and GetData(n) method.

TEST_CASE("Test GetData(20): y = 1.0 + 2.0 * x, for x in [0, 19]", "[LinearDataCreator]") {
  const double theta0 = 1.0;
  const double theta1 = 2.0;
  const int n = 20;
  lrg::LinearDataCreator LinearDataCreatorInstance(theta0, theta1);
  lrg::vector_of_pairs data = LinearDataCreatorInstance.GetData(n);
  REQUIRE(data.size() == n);

  std::fstream f;
  f.open("GetData.txt", std::fstream::out);
  for (auto item : data) {
    f << item.first << " " << item.second << std::endl;
  }
  f.close();
  
  //REQUIRE(data[0] == std::pair<double, double>(0.0, theta0));
  //REQUIRE(data[n - 1] == std::pair<double, double>(n - 1, theta0 + theta1 * (n - 1)));
}


//
// File Loader Data Creator Tests.
//

// Test the default constructor does actually construct an object of the correct type.

TEST_CASE("Test FileLoaderDataCreator default constructor", "[FileLoaderDataCreator]") {
  lrg::FileLoaderDataCreator creator;
  REQUIRE(typeid(creator) == typeid(lrg::FileLoaderDataCreator));
}


// Test loading TestData1.txt.

TEST_CASE("Test loading TestData1.txt", "[FileLoaderDataCreator]") {
  lrg::FileLoaderDataCreator creator("TestData1.txt");
  lrg::vector_of_pairs v = creator.GetData();
  REQUIRE(v.size() == 1000);
}


// Test loading TestData2.txt.

TEST_CASE("Test loading TestData2.txt", "[FileLoaderDataCreator]") {
  lrg::FileLoaderDataCreator creator("TestData2.txt");
  lrg::vector_of_pairs v = creator.GetData();
  REQUIRE(v.size() == 1000);
}


//
// Normal Equation Solver Strategy Tests.
//

// Test the default constructor does actually construct an object of the correct type.

TEST_CASE("Test NormalEquationSolverStrategy default constructor", "[NormalEquationSolverStrategy]") {
  lrg::NormalEquationSolverStrategy solver;
  REQUIRE(typeid(solver) == typeid(lrg::NormalEquationSolverStrategy));
}


// TODO(John): Test below for data vector length < 2.


// Basic test of fitting 2 points on the line y = x.

TEST_CASE("Test NormalEquationSolverStrategy y = x, for x in [0, 1]", "[NormalEquationSolverStrategy]") {
  lrg::vector_of_pairs data {lrg::single_pair(0.0, 0.0), lrg::single_pair(1.0, 1.0)};
  lrg::NormalEquationSolverStrategy Solver;
  lrg::single_pair theta = Solver.FitData(data);
  // Test for required output being careful of floating point comparisons.
  REQUIRE(round(theta.first) == 0.0);
  REQUIRE(round(theta.second) == 1.0);
}


// Basic test of fitting 3 points on the line y = x.

TEST_CASE("Test NormalEquationSolverStrategy y = x, for x in [0, 2]", "[NormalEquationSolverStrategy]") {
  lrg::vector_of_pairs data {lrg::single_pair(0.0, 0.0), lrg::single_pair(1.0, 1.0), lrg::single_pair(2.0, 2.0)};
  lrg::NormalEquationSolverStrategy Solver;
  lrg::single_pair theta = Solver.FitData(data);
  // Test for required output being careful of floating point comparisons.
  REQUIRE(round(theta.first) == 0.0);
  REQUIRE(round(theta.second) == 1.0);
}


// Test fitting the line y = 2 from 3 data points not on the line.

TEST_CASE("Test NormalEquationSolverStrategy y = 2, from 3 data points", "[NormalEquationSolverStrategy]") {
  lrg::vector_of_pairs data {lrg::single_pair(0.0, 1.0), lrg::single_pair(1.0, 3.0), lrg::single_pair(2.0, 1.0)};
  lrg::NormalEquationSolverStrategy Solver;
  lrg::single_pair theta = Solver.FitData(data);
  // Test for required output being careful of floating point comparisons.
  REQUIRE(round(theta.first) == 2.0);
  REQUIRE(round(theta.second) == 0.0);
}
