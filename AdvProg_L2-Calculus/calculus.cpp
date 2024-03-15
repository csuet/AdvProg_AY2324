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
    double cosx=0;
    for(int i=0;i<16;i++){
        cosx += (i % 2 == 0 ? 1 : -1) * pow(x, 2 * i) / tgamma(2 * i + 1);
    }
    return cosx;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double sinx=0;
    for(int i=0;i<16;i++){
        sinx += (i % 2 == 0 ? 1 : -1) * pow(x, 2 * i+1) / tgamma(2 * i + 1+1);
    }
    return sinx;
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
    double k=x;
    for(int i=0;i<10;i++){
        k=(k+x/k)/2;
    }
    
    return k;
}