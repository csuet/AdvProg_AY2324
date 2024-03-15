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
    int sh=1;
    int ans=0;
    for (int i=1;i<=16;i++)
    {
        ans+=sh;
        sh *= x*x/(2*i)/(2*i-1)*(-1);
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
    int sh=x;
    int ans=0;
    for (int i=1;i<=16;i++)
    {
        ans+=sh;
        sh *= x*x/(2*i)/(2*i+1)*(-1);
    }
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
    int ans=x;
    for(int i=1;i<=15;i++)
    {
        ans=(ans+x/ans)/2;
    }
    return ans;


}