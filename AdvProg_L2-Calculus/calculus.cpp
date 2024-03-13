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
    return 1 - 1/2*x*x + 1/24*x*x*x*x - 1/720 * x * x * x * x * x * x;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    return x - 1/6*x * x * x + 1/120 * x * x * x * x * x - 1/5040 * x * x * x * x * x * x * x;
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
const double eps = 1e-7;
double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    double x0 = 10;
    while (true){
        double y = x0*x0 - x;
        double y_prime = 2*x0;
        if (abs(y_prime) < eps) break;
        double x1 = x0 - y/y_prime;
        if (abs(x1 - x0) <= eps) return x1;
        x0 = x1;
    }
    return 0;
}