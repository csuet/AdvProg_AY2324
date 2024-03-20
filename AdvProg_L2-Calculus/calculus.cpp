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
	double n = cos(x);
    return n;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
	double n = sin(x);
    return n;
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
        return -1;
    }
    else 
    {
    	double n =sqrt(x);
    	return n;
	}
    
}