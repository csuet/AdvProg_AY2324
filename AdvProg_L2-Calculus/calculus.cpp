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
    double term = 1.0;
    double sum = term;
    int n = 0;
    while (true) {
        n += 2;
        term *= -(x * x) / (n * (n - 1));
        if (fabs(term) < 1 * pow(10 , - 9)) break;
        sum += term;
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
    double result = 0;
    double term = x;
    int n = 1;
    while (fabs(term) >= 1 * pow(10, -9)) {
        result += term;
        term *= -(x * x) / ((2 * n) * (2 * n + 1));
        n++;
    }
    return result;
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