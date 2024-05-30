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
double myCos(double x)
{
    double kq=cos(x);
    
    return kq;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double kq=sin(x);
   
    return kq;
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
    else
    {
        double k=sqrt(x);
        return k;
    }

    return 0;
}