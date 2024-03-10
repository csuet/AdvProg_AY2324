#include <iostream>
#include <string>
#include <cmath>

using std::cout;
using std::endl;
using std::stod;
using std::string;

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
    int a;
    double ans = 1 - (1 / 2) * pow(x, 2) + (1 / 24) * pow(x, 4) - (1 / 720) * pow(x, 6);
    return ans;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double ans = x - (1 / 6) * pow(x, 3) + (1 / 120) * pow(x, 5) - (1 / 5040) * pow(x, 7);
    return ans;
}

/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x)
{
    if (x < 0)
    {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    double ans = 10;
    for (int i = 0; i < 6; i++)
    {

        ans = ans - ((pow(ans, 2) - x) / (2 * ans));
    }

    return ans;
}
