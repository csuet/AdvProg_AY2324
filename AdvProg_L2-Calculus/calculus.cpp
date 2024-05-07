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
    double a = 2, giaiThua = 1;
    double sum = 1;
    double temp;
    do {
        giaiThua *= a * (a-1);
        temp = pow(-1, a/2) * pow(x, a) / giaiThua;
        sum += temp;
        a += 2;
    } while(a <= 300);

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
    double a = 2, giaiThua = 1;
    double sum = x;
    double temp;
    do {
        giaiThua *= (2*a-1) * (2*a-2);
        temp = pow(-1, a+1) * pow(x, 2*a - 1) / giaiThua;
        sum += temp;
        a++;
    } while(a <= 300);

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

    int a = 0;
    double temp = x;

    do{
        temp = temp - (pow(temp, 2)-x)/(2*temp);
        a++;
    } while (a <= 100);

    return temp;
}