#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::string;

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
    const double epsilon = 1e-15;
    double result = 1.0;
    double term = x;
    int sign = -1;
    for (int i = 2; i <= 100; i += 2)
    {
        term *= -x * x / (i * (i - 1));
        result += sign * term;
        sign = -sign;
        if (std::abs(term) < epsilon)
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
    return myCos(x - M_PI / 2);
}

/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x)
{
    if (x < 0)
    {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    double low = 0;
    double high = x;
    double mid;

    while (high - low > 1e-15)
    {
        mid = (low + high) / 2;
        if (mid * mid > x)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }

    return low;
}