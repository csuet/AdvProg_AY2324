#include <iostream>
#include <string>
#include <cmath>

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
  int factorial = 2;

  for (int i = 2; i <= 10; ++i) {  
    term *= -x * x / factorial;
    result += term;
    factorial *= (i + 1);
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

  for (int i = 2; i <= 10; ++i) {
    term *= -x * x / factorial;
    result += term;
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