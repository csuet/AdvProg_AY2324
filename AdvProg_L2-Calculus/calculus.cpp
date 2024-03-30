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
    

    return cos(x);
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
  return sin(x);
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) {
   
    double guess = x / 2.0; // Ước đoán ban đầu
    double oldGuess = 0.0;

    while (abs(guess - oldGuess) > 1e-6) {
        oldGuess = guess;
        guess = 0.5 * (guess + x / guess); // Lặp Newton-Raphson
    }

    return guess;

    
}