#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::stod;


double mySin(double x);
double myCos(double x);
double mySqrt(double x);
const double eps = 0.001;

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x)
{
    double sum=1, pso=1;
    int i=1;
    while( fabs(pso) > eps )
    {
        pso *= -(x*x)/(2*i*(2*i-1));
        sum += pso;
        i++;
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
    double sum=x, pso=x;
    int i=1;
    while( fabs(pso) > eps )
    {
        pso *= -(x*x)/(2*i*(2*i+1));
        sum += pso;
        i++;
    }

    return sum;
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

    double res = 1.0;
    while( fabs( res*res-x )/x > eps )
        res = (x/res - res)/2 + res;
    return res;
}
