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
    double sum = 0.0;
    double term = 1.0;
    double pow_x = -x * x;
    int n = 2;

    while (fabs(term) > 1e-8) 
    {
        sum += term;
        n += 2;
        term = -term * pow_x / (n * (n - 1));
    }

    return sum;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double sum = 0.0;
    double term = x;
    int n = 1;

    while (fabs(term) > 1e-8) 
    {
        sum += term;
        n += 2;
        term = term * x * x / (n * (n - 1));
    }

    return sum;
}


/***
    Args:
        x (double): a non-negative number
    Returns:
        double: square root of x
***/
double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }

    double guess = x / 2.0;
    const double EPSILON = 1e-8; 

    while (fabs(guess * guess - x) > EPSILON)
    {
        guess = (guess + x / guess) / 2.0;
    }

    return guess;
}