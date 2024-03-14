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
    int n=0;
    double temp=1,result=0.0;
    do{
        result += temp;
        n++;
        temp *= -x*x/((2*n-1)*2*n);
    }while( abs(temp) >0.0000001);
    return result;
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    double temp=x,result=0.0;
    int n=0;
    do {
        result += temp;
        n++;
        temp *= -x*x/(2*n*(2*n+1));
    }while (abs (temp) > 0.0000001);
    return result;
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

    
    else{
        double temp, a=1.0;
        while( abs(temp*temp - x) > 0.000001 ){
            temp = 0.5*(a+x/a);
            a=temp;
        }
    }
    return temp;
}
