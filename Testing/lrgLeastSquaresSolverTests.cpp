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
#include "lrgNormalDistributionNoise.h"
#include "lrgLinearDataCreator.h"
#include "lrgFileLoaderDataCreator.h"
#include "lrgNormalEquationSolverStrategy.h"
#include "lrgGradientDescentSolverStrategy.h"

#include <fstream>
#include <iostream>
#include <typeinfo>


//
// Noise Generator Tests.
//


TEST_CASE("Test NormalDistributionNoise constructor.", "[NormalDistributionNoise]") {

  // Create NormalDistributionNoise instance.

  lrg::NormalDistributionNoise noise(0.0, 1.0);  // Mean: 0.0, Standard Deviation: 1.0.
  
  // Test for the correct type.
  
  REQUIRE(typeid(noise) == typeid(lrg::NormalDistributionNoise));

}


TEST_CASE("Test NormalDistributionNoise output #1", "[NormalDistributionNoise]") {

  // Create NormalDistributionNoise instance.

  lrg::NormalDistributionNoise noise(0.0, 1.0);  // Mean: 0.0, Standard Deviation: 1.0.

  // Generate some noise.

  int n = 1000;
  double sum = 0.0;
  
  for (auto i = 0; i < n; ++i) {
    sum += noise.GetNumber();
  }
  
  // We should reasonably expect the mean of this to be 0.0.

  REQUIRE(round(sum / n) == 0.0);

}


TEST_CASE("Test NormalDistributionNoise output #2", "[NormalDistributionNoise]") {

  // Create NormalDistributionNoise instance.

  lrg::NormalDistributionNoise noise(1.0, 1.0);  // Mean: 1.0, Standard Deviation: 1.0.

  // Generate some noise.

  int n = 1000;
  double sum = 0.0;
  
  for (auto i = 0; i < n; ++i) {
    sum += noise.GetNumber();
  }
  
  // We should reasonably expect the mean of this to be 1.0.

  REQUIRE(round(sum / n) == 1.0);

}


//
// Linear Data Creator Tests.
//

TEST_CASE("Test LinearDataCreator constructor", "[LinearDataCreator]") {

  // Create NormalDistributionNoise instance (previously tested).

  lrg::NormalDistributionNoise noise(0.0, 0.0);  // no noise.

  // Create LinearDataCreatorInstance.

  lrg::LinearDataCreator creator(0.0, 1.0, noise);  // y = x, no noise. 

  // Test for the correct type.

  REQUIRE(typeid(creator) == typeid(lrg::LinearDataCreator));

}


TEST_CASE("Test LinearDataCreator, y = x without noise", "[LinearDataCreator]") {

  // Create NormalDistributionNoise instance (previously tested).

  lrg::NormalDistributionNoise noise(0.0, 0.0);  // no noise.

  // Create LinearDataCreatorInstance.

  lrg::LinearDataCreator creator(0.0, 1.0, noise);  // y = x. 

  // Create data.

  lrg::vector_of_pairs data;

  data = creator.GetData();

  // Test for correct values being careful of floating point comparisons.

  REQUIRE(data.size() == 1000);
 
  REQUIRE(round(data[0].first) == 0.0);
  REQUIRE(round(data[0].second) == 0.0);
  
  REQUIRE(round(data[999].first) == 999.0);
  REQUIRE(round(data[999].second) == 999.0);
  
}


TEST_CASE("Test LinearDataCreator, y = 1.0 with noise", "[LinearDataCreator]") {

  // Create NormalDistributionNoise instance (previously tested).

  lrg::NormalDistributionNoise noise(0.0, 1.0);  // Mean: 0.0, Standard Deviation: 1.0.

  // Create LinearDataCreatorInstance.

  lrg::LinearDataCreator creator(1.0, 0.0, noise);  // y = 1. 

  // Create data.

  lrg::vector_of_pairs data;

  data = creator.GetData();

  // Test for correct values being careful of floating point comparisons.

  REQUIRE(data.size() == 1000);

  double sum = 0.0;
  
  for (auto i = 0; i < data.size(); ++i) {
    sum += data[i].second;  // Sum y values.
  }

  // It is reasonable to expect the mean of the y values to be 1.0.

  REQUIRE(round(sum / data.size()) == 1.0);
  
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


//
// Gradient Descent Solver Strategy Tests.
//


// Test the constructor does actually construct an object of the correct type.

TEST_CASE("Test GradientDescentSolverStrategy constructor", "[GradientDescentSolverStrategy]") {

  // Create solver instance.

  lrg::single_pair theta_zero (5.0, 5.0);
  const int max_iterations = 1000;
  const double eta = 0.1;
  
  lrg::GradientDescentSolverStrategy solver(theta_zero, max_iterations, eta);

  // Test for the correct type.
  
  REQUIRE(typeid(solver) == typeid(lrg::GradientDescentSolverStrategy));

}


// Test solving for TestData1.txt.

TEST_CASE("Test GradientDescentSolverStrategy for TestData1.txt", "[GradientDescentSolverStrategy]") {

  // Get the data (this has previously been tested).

  lrg::FileLoaderDataCreator creator("TestData1.txt");
  lrg::vector_of_pairs data = creator.GetData();

  // Create solver instance.

  const lrg::single_pair theta_zero(5.0, 5.0);
  const int max_iterations = 1000;
  const double eta = 0.1;

  lrg::GradientDescentSolverStrategy solver(theta_zero, max_iterations, eta);

  // Solve.

  lrg::single_pair theta = solver.FitData(data);

  // Test for required output being careful of floating point comparisons.
  
  REQUIRE(round(theta.first) == 3.0);
  REQUIRE(round(theta.second) == 2.0);

}


// Test solving for TestData2.txt.

TEST_CASE("Test GradientDescentSolverStrategy for TestData1.2xt", "[GradientDescentSolverStrategy]") {

  // Get the data (this has previously been tested).

  lrg::FileLoaderDataCreator creator("TestData2.txt");
  lrg::vector_of_pairs data = creator.GetData();

  // Create solver instance.

  const lrg::single_pair theta_zero(5.0, 5.0);
  const int max_iterations = 1000;
  const double eta = 0.1;

  lrg::GradientDescentSolverStrategy solver(theta_zero, max_iterations, eta);

  // Solve.

  lrg::single_pair theta = solver.FitData(data);

  // Test for required output being careful of floating point comparisons.
  
  REQUIRE(round(theta.first) == 2.0);
  REQUIRE(round(theta.second) == 3.0);

}
