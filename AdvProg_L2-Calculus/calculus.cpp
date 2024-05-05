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
    int n = 0;
    double tmp = 1;
    double cosx = 0.0;
    do
    {
        cosx += tmp;
        n++;
        temp *= -x * x / ((2 * n - 1) * 2 * n);
    }
    while ( fabs(tmp) > 0.000001);
       return cosx;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double tmp = x;
    double sinx = 0.0;
    int n = 0;
    do
    {
        sinx += tmp;
        n++;
        temp *= -x * x / ( 2 * n * ( 2 * n + 1 ));
    }
    while ( fabs(tmp) > 0.000001 );
    return sinx;
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) {
    double sqrtx;
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    else {
    double tmp1;
    double tmp2 = 1.0;
    while ( fabs(tmp * tmp - x ) > 0.000001 )
    {
        tmp = 0.5 * ( a + x / a );
        tmp2 = tmp;
    }
    }
    return sqrtx;
}
