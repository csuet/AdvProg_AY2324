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

const int terms = 30;

unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{
    while (x > M_PI)
        x -= M_PI * 2;

    while (x < -M_PI)
        x += M_PI * 2;

    int i = 4;
    double lr = 1, res = 1 - pow(x, 2)/2;
    while (std::abs(lr - res) >= 0.001)
    {
        lr = res;
        res += pow(-1, i/2) * pow(x, i)/factorial(i);
        i += 2;
    }
    
    return res;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    while (x > M_PI)
        x -= M_PI * 2;

    while (x < -M_PI)
        x += M_PI * 2;

    int i = 5;
    double lr = x, res = x - pow(x, 3)/6;
    while (std::abs(lr - res) >= 0.001)
    {
        lr = res;
        res += pow(-1, (i-1)/2) * pow(x, i)/factorial(i);
        i += 2;
    }
    
    return res;
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
    double lr = x;
    double res = x/2;
    while (std::abs(lr - res) >= 0.001)
    {
        lr = res;
        res = lr - (lr * lr - x)/(2 * lr);
    }
    return res;
}