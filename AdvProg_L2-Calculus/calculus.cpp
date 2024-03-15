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
        x (double): a 
    Returns:
        double: cosiof x
***/
double myCos(double x) 
{
        double ans=0.0;
    double sh=1.0;
    for (int i=1;i<=16;i++)
    {
        
        ans+=sh;
        sh*=x*x/(2*i)/(2*i-1)*(-1);
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
    double ans=0.0;
    double sh=x;
    for (int i=1;i<=16;i++)
    {
        
        ans+=sh;
        sh*=x*x/(2*i)/(2*i+1)*(-1);
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
    double ans=x;
    for(int i=0;i<=15;i++)
    {
        ans=(ans+1.0*x/ans)/2;
    }


    
    return ans;
}