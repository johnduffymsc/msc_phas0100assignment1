PHAS0100Assignment1
------------------

## TestData1.txt

### CLI Output

![TestData1.txt](CLIScreenshotTestData1.png)

### Gnuplot Output

![TestData1.txt](LeastSquaresSolver_TestData1.png)

## TestData2.txt

### CLI Output

![TestData2.txt](CLIScreenshotTestData2.png)

### Gnuplot Output

![TestData2.txt](LeastSquaresSolver_TestData2.png)


Purpose
-------
Coursework 1 by John Duffy for PHAS0100 Research Computing with C++ 2019/2020 at UCL.

A command line interface program to perform Linear Regression.

Data is supplied from a data file via the --file option, or randomly generated if the --file option is not given. The data file format is a space delimited 'x y' pair, one pair on each line. In the absence of the --file option, linear data is generated with user specified intercept and gradient values, together with the mean and and standard deviation of random noise which is applied to the linear data.

The method used to solve the linear regression is one of 'normal_equations' or 'gradient_descent', which is selected via the --solver option.

The program returns the intercept and gradient of the linear regression.

Additionally, the program generates a Gnuplot script which can be used with Gnuplot to generate a PNG plot of the data and resultant regression line.


Installation and Build Instructions
-----------------------------------

This assignment has been submitted as a zip file, as required by the assignment instructions. To install from the zip file:

```
unzip 19154676.zip
cd 19154676
mkdir PHAS0100Assignment1-Build
cd PHAS0100Assignment1-Build
cmake ../PHAS0100Assignment1
make
```
To run the tests:
```
ctest -V
```
The executable, lrgLeastSquaresSolver, will be in the PHAS0100Assignment1-Build/bin directory.


Additionally, this assignment can be built from a private GitHub respository. The repository is private to prevent plagiarism, again, as required by the assignment instructions. To obtain the username and password for this repository please contact [John Duffy](mailto:john.duffy.19@ucl.ac.uk). To build from this repository:

```
git clone https://github.com/johnduffymsc/PHAS0100Assignment1.git
mkdir PHAS0100Assignment1-Build
cd PHAS0100Assignment1-Build
cmake ../PHAS0100Assignment1
make
```
To run the tests:
```
ctest -V
```
The executable, lrgLeastSquaresSolver, will be in the PHAS0100Assignment1-Build/bin directory.

In addition to displaying the values of theta0 and theta1 from the Linear Regression, the executble also produces a Gnuplot script which can be used to produce a png plot of input data and the resultant regression line. It is not necessary to install Gnuplot to produce the script, only to produce the png plot. To install Gnuplot (on Ubuntu 18.04):

```
sudo apt install gnuplot
```

Useage
------

From the PHAS0100Assignment1-Build directory:

```
bin/lrgLeastSquaresSolver --help
```
yields the following:
```
A program to perform Linear Regression.
Usage: bin/lrgLeastSquaresSolver [OPTIONS]

Options:
  -h,--help                   Print this help message and exit
  -f,--file TEXT:FILE REQUIRED
                              Data file, space separated X and y pairs, one pair per line.
  -s,--solver TEXT:{normal_equations,gradient_descent} REQUIRED
                              Solver to perform linear regression.
```

The executable will automatically produce a Gnuplot script in the directory the executable was run from. To produce a png plot of the input data and resultant regression line from this script:

```
gnuplot LeastSquaresSolver.plt
```

This will produce LeastSquaresSolver.png in the same directory.
