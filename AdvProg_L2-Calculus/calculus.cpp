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
double factorial(int n);

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double factorial(int n) {
        return (n==0)? 1 : n*factorial(n - 1);
    }
double myCos(double x)
{
    double result =0;
    int n=0;
    for (int i=0;i<10;i++) {
        result += std::pow(-1, n)*std::pow(x, 2 * n)/factorial(2 * n);
        n++;
    }
    return result;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double result =0;
    int n=0;
    for (int i=0;i<10;i++) {
        result+=std::pow(-1, n)*std::pow(x,2*n+1)/factorial(2*n+1);
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
    else
    {
    if (x==0||x==1)
        return x;
    double epsilon = 0.001;
    double guess = x / 2;
    while (true) {
        double diff= x - guess * guess;
        if (diff<0) diff = -diff;
        if (diff<=epsilon)
            return guess;
        guess=(guess+x/guess)/2;
    }
    }
}
