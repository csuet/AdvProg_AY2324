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
    long double ans = 1.0 - pow(x,2)/2 + pow(x,4)/24 - pow(x,6)/720 + pow(x,8)/40320;
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
    long double ans = x - pow(x,3)/6 + pow(x,5)/120 - pow(x,7)/5040 + pow(x,9)/362880;
    return ans;
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