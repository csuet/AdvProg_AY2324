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
    double coss = cos(x);
    return coss;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double sinn = sin(x);
    return sinn;
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) {
    double sqrtt;
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    else {
    sqrtt = sqrt(x);
    }
    return sqrtt;
}
