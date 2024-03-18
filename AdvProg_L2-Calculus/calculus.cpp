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
    double old_value;
    double value = 1;
    int n = 1;
    do{
        old_value = value;
        double mul = 1;
        for (int i = 1; i < 2*n; i++){
            mul*=i;
        }
        value += ( pow( -1, n)*pow( x, 2 * n))/mul;
        n++;
    }
    while (value - old_value >= 0.1);
    return value;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double old_value;
    double value = x;
    int n = 1;
    do{
        old_value = value;
        double mul = 1;
        for (int i = 1; i < 2*n+1; i++){
            mul*=i;
        }
        value += (pow(-1,n)*pow(x,2*n+1))/mul;
        n++;
    }
    while (value - old_value >= 0.1);
    return value;
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
    } else{
        return sqrt(x);
    }
}
