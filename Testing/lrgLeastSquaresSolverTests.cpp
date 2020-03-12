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


TEST_CASE("Test NormalDistributionNoise constructor.", "[NormalDistributionNoise]")
{
  lrg::NormalDistributionNoise noise(0.0, 1.0);  // Mean: 0.0, Standard Deviation: 1.0.
  REQUIRE(typeid(noise) == typeid(lrg::NormalDistributionNoise));
}


TEST_CASE("Test NormalDistributionNoise output #1", "[NormalDistributionNoise]")
{
  lrg::NormalDistributionNoise noise(0.0, 1.0);  // Mean: 0.0, Standard Deviation: 1.0.
  int n = 1000;
  double sum = 0.0;  
  for (auto i = 0; i < n; ++i) {
    sum += noise.GetNumber();
  }
  // Be careful of floating point comparisons.
  REQUIRE(round(sum / n) == 0.0);
}


TEST_CASE("Test NormalDistributionNoise output #2", "[NormalDistributionNoise]")
{
  lrg::NormalDistributionNoise noise(1.0, 1.0);  // Mean: 1.0, Standard Deviation: 1.0.
  int n = 1000;
  double sum = 0.0;  
  for (auto i = 0; i < n; ++i) {
    sum += noise.GetNumber();
  }
  // Be careful of floating point comparisons.
  REQUIRE(round(sum / n) == 1.0);
}


//
// Linear Data Creator Tests.
//


TEST_CASE("Test LinearDataCreator constructor", "[LinearDataCreator]")
{
  lrg::NormalDistributionNoise noise(0.0, 0.0);  // no noise.
  lrg::LinearDataCreator creator(0.0, 1.0, noise);  // y = x, no noise. 
  REQUIRE(typeid(creator) == typeid(lrg::LinearDataCreator));
}


TEST_CASE("Test LinearDataCreator, y = x without noise", "[LinearDataCreator]")
{
  lrg::NormalDistributionNoise noise(0.0, 0.0);  // no noise.
  lrg::LinearDataCreator creator(0.0, 1.0, noise);  // y = x. 
  lrg::vector_of_pairs data;
  data = creator.GetData();
  REQUIRE(data.size() == 1000); 
  // Be careful of floating point comparisons.
  REQUIRE(round(data[0].first) == 0.0);
  REQUIRE(round(data[0].second) == 0.0);
  REQUIRE(round(data[999].first) == 999.0);
  REQUIRE(round(data[999].second) == 999.0);
}


TEST_CASE("Test LinearDataCreator, y = 1.0 with noise", "[LinearDataCreator]")
{
  lrg::NormalDistributionNoise noise(0.0, 1.0);  // Mean: 0.0, Standard Deviation: 1.0.
  lrg::LinearDataCreator creator(1.0, 0.0, noise);  // y = 1. 
  lrg::vector_of_pairs data;
  data = creator.GetData();
  REQUIRE(data.size() == 1000);
  double sum = 0.0;
  for (auto i = 0; i < data.size(); ++i) {
    sum += data[i].second;  // Sum y values.
  }
  // Be careful of floating point comparisons.
  REQUIRE(round(sum / data.size()) == 1.0);  
}


//
// File Loader Data Creator Tests.
//


// TODO(John): Fix! A primary expression is required in the REQUIRE_THROWS(), ???
//TEST_CASE("Test FileLoaderDataCreator exception due to file not found", "[FileLoaderDataCreator]") {
//  REQUIRE_THROWS(lrg::FileLoaderDataCreator creator("Blah.txt"));
//}


// TODO(John): Fix! A primary expression is required in the REQUIRE_THROWS(), ???
//TEST_CASE("Test FileLoaderDataCreator exception due to file not found", "[FileLoaderDataCreator]") {
//  REQUIRE_THROWS(lrg::FileLoaderDataCreator creator("Blah.txt"));
//}


TEST_CASE("Test FileLoaderDataCreator constructor", "[FileLoaderDataCreator]") {
  lrg::FileLoaderDataCreator creator("TestData1.txt");
  REQUIRE(typeid(creator) == typeid(lrg::FileLoaderDataCreator));
}


TEST_CASE("Test loading TestData1.txt", "[FileLoaderDataCreator]") {
  lrg::FileLoaderDataCreator creator("TestData1.txt");
  lrg::vector_of_pairs v = creator.GetData();
  REQUIRE(v.size() == 1000);
}


TEST_CASE("Test loading TestData2.txt", "[FileLoaderDataCreator]") {
  lrg::FileLoaderDataCreator creator("TestData2.txt");
  lrg::vector_of_pairs v = creator.GetData();
  REQUIRE(v.size() == 1000);
}


//
// Normal Equation Solver Strategy Tests.
//


TEST_CASE("Test NormalEquationSolverStrategy constructor", "[NormalEquationSolverStrategy]") {
  lrg::NormalEquationSolverStrategy solver;
  REQUIRE(typeid(solver) == typeid(lrg::NormalEquationSolverStrategy));
}


TEST_CASE("Test NormalEquationSolverStrategy y = x, for x in [0, 1]", "[NormalEquationSolverStrategy]") {
  lrg::vector_of_pairs data {lrg::single_pair(0.0, 0.0), lrg::single_pair(1.0, 1.0)};
  lrg::NormalEquationSolverStrategy solver;
  lrg::single_pair theta = solver.FitData(data);
  // Test for required output being careful of floating point comparisons.
  REQUIRE(round(theta.first) == 0.0);
  REQUIRE(round(theta.second) == 1.0);
}


TEST_CASE("Test NormalEquationSolverStrategy y = x, for x in [0, 2]", "[NormalEquationSolverStrategy]")
{
  lrg::vector_of_pairs data {lrg::single_pair(0.0, 0.0), lrg::single_pair(1.0, 1.0), lrg::single_pair(2.0, 2.0)};
  lrg::NormalEquationSolverStrategy solver;
  lrg::single_pair theta = solver.FitData(data);
  // Test for required output being careful of floating point comparisons.
  REQUIRE(round(theta.first) == 0.0);
  REQUIRE(round(theta.second) == 1.0);
}


TEST_CASE("Test NormalEquationSolverStrategy y = 2, from 3 data points", "[NormalEquationSolverStrategy]")
{
  lrg::vector_of_pairs data {lrg::single_pair(0.0, 1.0), lrg::single_pair(1.0, 3.0), lrg::single_pair(2.0, 1.0)};
  lrg::NormalEquationSolverStrategy Solver;
  lrg::single_pair theta = Solver.FitData(data);
  // Test for required output being careful of floating point comparisons.
  REQUIRE(round(theta.first) == 2.0);
  REQUIRE(round(theta.second) == 0.0);
}


TEST_CASE("Test NormalEquationSolverStrategy for TestData1.txt", "[NormalEquationSolverStrategy]")
{
  lrg::FileLoaderDataCreator creator("TestData1.txt");
  lrg::vector_of_pairs data = creator.GetData();
  lrg::NormalEquationSolverStrategy solver;
  lrg::single_pair theta = solver.FitData(data);
  REQUIRE(round(theta.first) == 3.0);
  REQUIRE(round(theta.second) == 2.0);
}


TEST_CASE("Test NormalEquationSolverStrategy for TestData1.2xt", "[NormalEquationSolverStrategy]")
{
  lrg::FileLoaderDataCreator creator("TestData2.txt");
  lrg::vector_of_pairs data = creator.GetData();
  lrg::NormalEquationSolverStrategy solver;
  lrg::single_pair theta = solver.FitData(data);
  REQUIRE(round(theta.first) == 2.0);
  REQUIRE(round(theta.second) == 3.0);
}


//
// Gradient Descent Solver Strategy Tests.
//


TEST_CASE("Test GradientDescentSolverStrategy constructor", "[GradientDescentSolverStrategy]")
{
  lrg::single_pair theta_zero (5.0, 5.0);
  const int max_iterations = 1000;
  const double eta = 0.1;  
  lrg::GradientDescentSolverStrategy solver(theta_zero, max_iterations, eta);
  REQUIRE(typeid(solver) == typeid(lrg::GradientDescentSolverStrategy));
}


TEST_CASE("Test GradientDescentSolverStrategy for TestData1.txt", "[GradientDescentSolverStrategy]")
{
  lrg::FileLoaderDataCreator creator("TestData1.txt");
  lrg::vector_of_pairs data = creator.GetData();
  const lrg::single_pair theta_zero(5.0, 5.0);
  const int max_iterations = 1000;
  const double eta = 0.1;
  lrg::GradientDescentSolverStrategy solver(theta_zero, max_iterations, eta);
  lrg::single_pair theta = solver.FitData(data);
  REQUIRE(round(theta.first) == 3.0);
  REQUIRE(round(theta.second) == 2.0);
}


TEST_CASE("Test GradientDescentSolverStrategy for TestData1.2xt", "[GradientDescentSolverStrategy]")
{
  lrg::FileLoaderDataCreator creator("TestData2.txt");
  lrg::vector_of_pairs data = creator.GetData();
  const lrg::single_pair theta_zero(5.0, 5.0);
  const int max_iterations = 1000;
  const double eta = 0.1;
  lrg::GradientDescentSolverStrategy solver(theta_zero, max_iterations, eta);
  lrg::single_pair theta = solver.FitData(data);
  REQUIRE(round(theta.first) == 2.0);
  REQUIRE(round(theta.second) == 3.0);
}
