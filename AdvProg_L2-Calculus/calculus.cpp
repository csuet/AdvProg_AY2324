#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;


double mySin(double x);
double myCos(double x);
double mySqrt(double x);

double gt(int n){
	if(n==0 || n==1){
		return 1;
	}
	else{
		return n*gt(n-1);
	}
}
double luythua(int x, int n){ 
    if(n==0) return 1;
    double result = 1;
    for (int i = 1; i < 1000; ++i) {
        result *= x;
    }
    return result;
}
double myCos(double x) {
    double result = 0;
    for (int i = 0; i < 1000; i++) {
        result += luythua(-1, i) * luythua(x, 2 * i) / gt(2 * i);
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
     double result = 0;
    for (int i = 0; i < 1000; i++) {
        result += luythua(-1, i) * luythua(x, 2 * i + 1) / gt(2 * i + 1);
    }
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
	
      double result = 0;
      for (int i = 0; i < 1000; ++i) {
        result += luythua(-1, i) * luythua(gt(2 * i), 2) * luythua(x - 1, i) / (gt(i) * gt(i) * luythua(4, i) * (2 * i + 1));
      }
   }
}

    

