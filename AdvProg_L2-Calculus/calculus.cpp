#include <iostream>
#include <string>
#include <cmath>
#include "calculus.h"

using std::string;
using std::cout;
using std::endl;
using std::stod;


double mySin(double x);
double myCos(double x);
double mySqrt(double x);

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{
    
     double result = 1.0;
    double term = 1.0;
    int factorial = 1; 
    int i = 2; 

    double prevSequence = 1;
    double currentSequence = 1 - (x * x) / 2; 

    const double tolerance = 0.001;

    while (std::abs(prevSequence - currentSequence) >= tolerance) { 
        prevSequence = currentSequence;

        term *= -x * x;
        factorial *= (2 * i - 1) * (2 * i); 
        currentSequence += term / factorial;

        i += 2;

        result = currentSequence; 
    }

    return result;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
 double result = x;
    double term = x;
    int factorial = 3;

    double prevSequence = x; 
    double currentSequence = x;

    for (int i = 2; i <= 10; ++i) {
        term *= -x * x / factorial;
        prevSequence = currentSequence;
        currentSequence += term;

        result = currentSequence; 
        factorial *= (i + 1);
    }

    return result;
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    double guess = 1.0;
  double epsilon = 0.00001; 

  while (std::abs(guess * guess - x) > epsilon) {
    guess = (guess + x / guess) / 2.0;
  }

  return guess;
}