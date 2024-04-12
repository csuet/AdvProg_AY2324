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
//    double pi = 3.14159265358979323846;
//    x = x * pi / 180;
    double res = 1;
    double add = 1;
    for(int i = 1;; i++)
    {
        add *= -1;
        add *= (x * x) / (2 * i * (2 * i - 1));
        if(std::abs(add) < 0.1e-200) break;
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
    double y = myCos(x);
    double ans = 1;
    ans -= y * y;
    ans = mySqrt(ans);
    return ans;
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

    if(x == 0) return 0;

    double ans = 0;
    double guess = x;
    while(1)
    {
        ans = 0.5 * (guess + (x / guess));
        if(std::abs(ans - guess) < 1e-10) break;
        guess = ans;
    }

    return ans;
}
