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

double gt(int a,double x);
/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double gt(int a,double x)
{
    double result = 1.0;

    for(int i=1;i<=a;i++){
        result=result * x/i;
    }
    return result;
}
double myCos(double x) 
{ double result=1;
    for(int i=2;i<50;i++){
        if(i%4==0){
            result+=gt(i,x);

        }
         if(i%4==2){
            result-=gt(i,x);

        }
    }
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
   return myCos(3.14159265359/2-x);
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
    double temp=1.1;
    
for(int i=1;i<100;i++){
    temp=(temp+x/temp)/2.0;
}

    
    return temp;
}
double myPlus(int a,int b){
    return a+b;
}