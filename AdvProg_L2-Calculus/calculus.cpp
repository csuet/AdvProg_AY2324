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
	double cos = 1, oldCos = 0;
	int i = 1;
	double a = 1;
	while(abs(cos - oldCos) > 0.001)
	{
		oldCos = cos;
		a *= (-1)*x*x/(2*i*(2*i - 1));
		cos += a;
		i++;
	}	
    return cos;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
	double sin;
	sin = mySqrt(1-myCos(x)*myCos(x));
    return sin;
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
		int x0 = sqrt(int(x+1));
		double sqrt = x0, oldSqrt = 0;
		int i = 1;
		while(i < 10)
		{
			oldSqrt = sqrt;
			sqrt = (oldSqrt + x/oldSqrt) / 2;
			i++;
		}
		return sqrt;
	}
}

