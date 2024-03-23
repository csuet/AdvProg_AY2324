#include <bits/stdc++.h>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;

const double pi = 3.14159265359;


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
    double res=0;
    int j=0;
    long long fac=1;
    for(int i=0;i<=12;++i)
    {
        while(j<2*i)
        {
            j++;
            fac*=j;
        }
        double add = pow(x,2*i)/fac;
        if(i%2==1) add=-add;
        res+=add;
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
    double res=0;
    int j=0;
    long long fac=1;
    for(int i=0;i<=12;++i)
    {
        while(j<2*i+1)
        {
            j++;
            fac*=j;
            //cout<<fac<<" ";
        }
        double add = pow(x,2*i+1)/fac;
        if(i%2==1) add=-add;
        res+=add;
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

    double an=10;
    for(int i=0;i<15;++i)
    {
        an=(an+x/an)/2;
        //cout<<an<<" ";
    }

    return an;
}
//
//int main()
//{
//    cout<<mySin(pi-pi/3)<<" "<<sin(pi/3);
//}
