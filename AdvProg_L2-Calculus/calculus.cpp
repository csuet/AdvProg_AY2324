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
    return (1 - pow(x, 2)/2 + pow(x, 4)/24 - pow(x, 6)/720);
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    return (x - pow(x, 3)/6 + pow(x, 5)/120 - pow(x, 7)/5040);
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
    double lastSequence = x;
    double newSequence = x/2;
    while (std::abs(lastSequence - newSequence) >= 0.001)
    {
        lastSequence = newSequence;
        newSequence = lastSequence - (lastSequence * lastSequence - x)/(2 * lastSequence);
    }
    return newSequence;
}