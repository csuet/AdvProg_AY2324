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
    double sum=1, pso=1;
    int i=1;
    while( abs(pso) > 0.001 )
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
    double sum=x, pso=1;
    int i=2;
    while( abs(pso) > 0.001 )
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

double f( double x )
{
    return x*x-2;
}

double f_prime( double x )
{
    return 2*x;
}

double mySqrt(double x) {
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }

    double x0=1, x1, y, yprime;
    while( abs(f_prime(x0)) > 0.001 )
    {
        y = f(x0);
        yprime = f_prime(x0);
        x1 = x0 - y/yprime;
        if( abs(x1-x0) <= 0.001 ) return x1;

        x0 = x1;
    }

    cout << "Invalid argument" << endl;
    exit(1);
    return 0;
}
