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
    double acc = 0.0001, temp, denominator, cosx, realCos;
    temp = 1;
    cosx = temp;          
    realCos = cos(x);
    int i = 1;
    do {
        denominator = 2 * i * (2 * i - 1);
        temp = -temp * x * x / denominator;
        cosx = cosx + temp;
        i = i + 1;
    } while (acc <= fabs(realCos - cosx));
    return cosx;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double error = 0.0001, denominator, sinx, realSin;
    double temp = x;
    sinx = x;          
    realSin = sin(x);    
    int i = 1;
    do {
        denominator = 2 * i * (2 * i + 1);
        temp = -temp * x * x / denominator;
        sinx = sinx + temp;
        i = i + 1;
    } while (error <= fabs(realSin - sinx));
    return sinx;
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
 
    // considering the equation values
    double guess = x;
    double closerGuess = (x + 1)/2;
 
    // as we want to get upto 5 decimal digits, the absolute
    // difference should not exceed 0.00001
    while (fabs(guess - closerGuess) >= 0.00001) {
        guess = closerGuess;
        closerGuess = (guess + (x / guess)) / 2;
    }
    
    return closerGuess;
}