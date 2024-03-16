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

const int terms = 30;

int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;
    return result;
}

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{
    double result = 0;
    for (int n = 0; n <= 5; ++n)
        result += ((n % 2 == 0 ? 1 : -1) * x * x) / factorial(2 * n);
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
    double result = 0;
    for (int n = 0; n <= 5; ++n)
        result += ((n % 2 == 0 ? 1 : -1) * x) / factorial(2 * n + 1);
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

    if (x == 0)
        return 0;

    return exp(0.5 * log2(x)/log2(2.71828182846));
}