#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;
using std::abs;

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
    long double ans = 1.0 - pow(x,2)/2 + pow(x,4)/24 - pow(x,6)/720 + pow(x,8)/40320; // Taylor cosx

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
    long double ans = x - pow(x,3)/6 + pow(x,5)/120 - pow(x,7)/5040 + pow(x,9)/362880; //Taylor sinx
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
    double x0 = 10; // initial guess
    while (true){
        double y = x0*x0 - x; // function f(x) = x0^2 - x
        double y_prime = 2*x0; //derivatives of f(x)
        if (abs(y_prime) < eps) break; // if derivatives is too small then terminate to avoid further error
        double x1 = x0 - y/y_prime; // calculate new guess
        if (abs(x1 - x0) <= eps) return x1; // if new guess is not different from old guess then take
        x0 = x1; // start again
    }
    return 0;
}