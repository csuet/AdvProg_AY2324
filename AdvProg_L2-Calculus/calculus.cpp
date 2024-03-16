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
    double ans = 1.0 * cos(x);
    return ans;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double ans = 1.0 * sin(x);
    return ans;
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) {
    double ans 1.0 * sqrt(x);
    return ans;
}
