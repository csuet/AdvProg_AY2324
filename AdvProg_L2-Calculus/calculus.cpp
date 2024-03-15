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

double giaithua(int x){
    double ans = 1;
    for(int i = 1; i <= x; i ++)
        ans *= i;
    return ans;
}

double myCos(double x)
{
    double ans = 0;
    for(int n = 0; n < 10; n ++)
        ans += (pow(-1, n) / giaithua(2 * n)) * pow(x, 2 * n);
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
    double ans = 0;
    for(int n = 0; n < 10; n ++)
        ans += (pow(-1, n) / giaithua(2 * n + 1)) * pow(x, 2 * n + 1);
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
    int i;
    for(i = 1; i * i <= x; i ++);

    return i;
}
