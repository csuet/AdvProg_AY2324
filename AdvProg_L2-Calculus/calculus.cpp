#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::stod;
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
int factorial(int n)
{
    int result = 1;
    for (int i = 1; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}
double myCos(double x)
{
    int terms = 10;
    double result = 1;
    double sign = -1;
    for (int i = 2; i <= terms * 2; i += 2)
    {
        result += sign * pow(x, i) / factorial(i);
        sign *= -1;
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
    int terms = 10;
    double result = x;
    double sign = -1;
    for (int i = 3; i <= terms * 2 + 1; i += 2)
    {
        result += sign * pow(x, i) / factorial(i);
        sign *= -1;
    }
    return result;
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
        return -1;
    }
    else
    {
        return sqrt(x);
    }
}