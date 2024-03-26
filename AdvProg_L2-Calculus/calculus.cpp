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
    double sum=1, oldsum=0;
    double k=1, h=1;
    int i=2;
    while ( fabs(sum-oldSum) > 0.001 )
    {
        oldSum=sum;
        k=k*i*(i-1);
        h=h*(-x*x);
        sum+=h/k;
        i+=2;
    }
    return sum;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double x;
    cin >> x;
    double sum=x, oldSum=0;
    double k=1, h=x;
    int i=3;
    while ( fabs(sum-oldSum) > 0.001 )
    {
        oldSum=sum;
        k=k*i*(i-1);
        h=h*(-x)*x;
        sum+=h/k;
        i+=2;
    }
    return sum;
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x)
{
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    double result = 1.0;
    while (fabs(result * result - x) / x >= 0.0001)
        result = (xs / result  - result) / 2 + result;
    return result;
}
