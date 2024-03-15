#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;

unsigned long long factorial(int n);
double mySin(double x);
double myCos(double x);
double mySqrt(double x);

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
    double lastSequence = 1, newSequence = 1 - pow(x, 2)/2;
    while (std::abs(lastSequence - newSequence) >= 0.001)
    {
        lastSequence = newSequence;
        newSequence += pow(-1, i/2) * pow(x, i)/factorial(i);
        i += 2;
    }
    
    return newSequence;
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
    double lastSequence = x, newSequence = x - pow(x, 3)/6;
    while (std::abs(lastSequence - newSequence) >= 0.001)
    {
        lastSequence = newSequence;
        newSequence += pow(-1, (i-1)/2) * pow(x, i)/factorial(i);
        i += 2;
    }
    
    return newSequence;
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