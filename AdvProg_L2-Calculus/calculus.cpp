#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;
using std::abs;

const long double eps = 1e-144;

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
    double res = 1, add = 1;
    for (int i = 1; ; ++ i) {
        add *= -((x * x) / (i * 2 * (i * 2 - 1)));
        if (abs(add) < eps) break;
        res += add;
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
    double Cos = myCos(x);
    return mySqrt(double(1) - Cos * Cos);
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

    if (x == 0) return 0;

    double ans = 0, pre = x;
    while (1) {
        ans = 0.5 * (pre + (x / pre));
        if (abs(ans - pre) < eps) break;
        pre = ans;
    }

    return ans;
}
