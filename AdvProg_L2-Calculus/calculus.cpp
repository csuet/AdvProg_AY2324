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
    double result1;
    result1=cos(x);
    return result1;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double result2;
    result2=sin(x);
    return result2;
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) {
    double rs3;
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    else rs3=sqrt(x);


    return rs3;
}
