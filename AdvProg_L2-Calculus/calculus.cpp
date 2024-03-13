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
	
double result = 0.0;
    double term = 1;
    int sign = 1;
    for (int i = 0; i <= 10; ++i) { // Number of terms in the series (adjust as needed)
        result += sign * term;
        term *= -1 * x * x / ((2 * i + 1) * (2 * i + 2));
        sign *= -1;
    }
    return result;}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
double result = 0.0;
    double term = x;
    int sign = 1;
    for (int i = 1; i <= 10; ++i) { 
        result += sign * term;
        term *= -1 * x * x / ((2 * i) * (2 * i + 1));
        sign *= -1;
    }
    return result;}


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

    double guess = x / 2; // Initial guess (can be arbitrary)
    double threshold = 1e-6; // Threshold for convergence (adjust as needed)
    while (abs(guess * guess - x) > threshold) {
        guess = (guess + x / guess) / 2;
    }
    return guess;
}
