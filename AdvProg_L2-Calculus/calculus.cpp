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
    double s = 1;

    double t = 1;
    for (int i = 2; i <= 16; i += 2)
    {

        t *= (x * x) * (-1) / (i * (i - 1));
        s += t;
    }
    return s;
   
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double s = 0;
    double t = x;
    for (int i = 3; i <= 17; i += 2)
    {
        s += t;
        t *= (-1) * (x * x) / (i * (i - 1));

    }
    return s;
    
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
    else
    {
        double kq = x ;
        for (int i = 1; i <= 10; i++)
        {
            kq = (kq +  x / kq) / 2;

        }
        return kq;
    }
    
    return 0;
}