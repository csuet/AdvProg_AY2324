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
    double ket_qua = 0.0;
    int giai_thua = 1;
    for (int i = 0; i < 16; i++)
    {
        if (i == 0)
        {
            giai_thua = 1;
            ket_qua += 1.0;
        }
        else if (i % 2 == 0)
        {
            giai_thua *= i;
            ket_qua += pow(-1, i / 2) * pow(x, i) / giai_thua;
        }
        else
        {
            giai_thua *= i;
        }
    }
    return ket_qua;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double ket_qua = 0.0;
    int giai_thua = 1;
    for (int i = 0; i < 16; i++)
    {
        if (i == 0)
        {
            continue;
        }
        else
        {
            giai_thua *= i;
        }
        if (i % 2 == 1)
        {
            ket_qua += pow(-1, (i - 1) / 2) * pow(x, i) / giai_thua;
        }
        else
        {
            continue;
            ;
        }
    }
    return ket_qua;
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
    else
    {
        double ket_qua = x;
        for (int i = 0; i < 10; i++)
        {
            ket_qua = (ket_qua + x / ket_qua) / 2;
        }
        return ket_qua;
    }
}