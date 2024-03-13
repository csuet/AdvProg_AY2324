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
double myCos(double x) {
    double ans, T, fac, exp;
    int sign = 1;
    ans = 0;
    T = exp = fac = 1;
    for (int i = 2; T > 0.001; i += 2) {
        T = exp / fac;
        exp *= x * x; fac *= i * (i - 1);
        ans += sign * T; sign *= -1;
    }
    return ans;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x) {
    double ans, T, fac, exp;
    int sign = 1;
    ans = 0;
    T  = fac = 1; exp = x;
    for (int i = 3; T > 0.001; i += 2) {
        T = exp / fac;
        exp *= x * x; fac *= i * (i - 1);
        ans += sign * T; sign *= -1;
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