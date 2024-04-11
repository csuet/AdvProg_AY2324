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
    double x1 = 1;
    float def;
    double coss = 1;
    double oldcoss = 1;
    int i = 1;
    do{
        def = 2*i*(2*i-1);
        x1 = -x1*x*x/def;
        oldcoss = coss;
        coss += x1;
        i++;
    }while(abs(coss-oldcoss)>=0.0001);
    return coss;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double x1 = x;
    float def;
    double sinn = x;
    double oldsinn = 1;
    int i = 1;
    do{
        def = 2*i*(2*i+1);
        x1 = -x1*x*x/def;
        oldsinn = sinn;
        sinn += x1;
        i++;
    }while(abs(sinn-oldsinn)>=0.0001);
    return sinn;
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
    else
    {
    	double x1 = x;
        double root;
        while(1)
        {
            root = 0.5*(x1 + x/x1);
            if(abs(root-x1)<0.0001) break;
            x1 = root;
        }
        cout<<root;
	}
}