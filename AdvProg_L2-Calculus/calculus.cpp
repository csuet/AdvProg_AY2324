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
    double ans =0;
    for(int i = 0;i<13;i++){
        double ok =1;
        for(int j =1;j<=i*2;j++){
            ok*=x / j;
        }
        
        if(i%2==1) ok*=-1;
        ans+=ok;
    }
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
    int a;
    double ans =0;
    for(int i = 0;i<13;i++){
        double ok =1;
        for(int j =1;j<=i*2+1;j++){
            ok*=x / j;
        }
        if(i%2==1) ok*=-1;
        ans+=ok;
    }
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
    for (int i = 0; i < 8; i++)
    {

        ans = ans - ((pow(ans, 2) - x) / (2 * ans));
    }

    return ans;
}