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

const double EPSILON = 0.001;


/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x)
{
    double result = 0.0;
    double term = x;
    int sign = 1;

    for(int n = 1; n < 50; n++)
    {
        result += term;
        sign = -sign;
        term *= x * x / ((2 * n + 1) * (2 * n + 2));
        if(std::abs(term) < EPSILON)
        {
            break;
        }
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
    double result = 0.0;
    double term = x;
    int sign = 1;

    for(int n = 1; n < 50; n++)
    {
        result += term;
        sign = -sign;
        term *= x * x / ((2 * n) * (2 * n + 1));
        if(std::abs(term) < EPSILON)
        {
            break;
        }
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

    double x0 = x;
    double x1 = (x0 + x / x0) / 2;

    while(std::abs(x1 - x0) >= EPSILON)
    {
        x0 = x1;
        x1 = (x0 + x / x0) / 2;
    }


    return x1;
}
