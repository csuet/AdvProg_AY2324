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
    double cur=1;
    double ans=1;
    
    for (double i=1.0;i<=99.0;i+=1.0)
    {
        cur*=x*x;
        cur/=2.0*i*(2.0*i-1.0);
        cur=-cur;
        ans=ans+cur;
    }
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
    double cur=x;
    double ans=x;
    
    for (double i=1.0;i<=99.0;i+=1.0)
    {
        cur*=x*x;
        cur/=2.0*i*(2.0*i+1.0);
        cur=-cur;
        ans=ans+cur;
    }
    return ans;
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
    return sqrt(x);
}