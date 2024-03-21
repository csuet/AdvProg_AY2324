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
const int MAX_NUM = 10;
int giaithua(int n) {
    if (n == 1) return 1;
    else 
        return n * giaithua(n - 1);

}
double myCos(double x) 
{
    double res = 0.0;
    for (int i = 1; i < MAX_NUM; i++) {
        res += pow(-1, i) * pow(x, 2 * i) / (double)giaithua(2*i);
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
    double res = 0.0;
    for (int i = 0; i < MAX_NUM; i++) {
        res += pow(-1, i) * pow(x, (2*i+1) / (double)giaithua(2*i+1);
    }

    return res;
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
    double precision = 1e-6;
    double  y = 1;
    double num = x;
    while (num - y > precision) {
        num = (num + y) / 2;
        y = x / num;
    }
    return num;
   
    
}