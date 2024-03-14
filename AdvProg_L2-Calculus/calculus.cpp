#include <iostream>
#include <cmath> // Include cmath for M_PI constant

using std::cout;
using std::endl;

/***
    Computes the cosine of x using Taylor series expansion.
***/
double myCos(double x)
{
    const double epsilon = 1e-15;
    double result = 1.0;
    double term = x;
    int sign = -1;
    for (int i = 2; i <= 100; i += 2)
    {
        term *= -x * x / (i * (i - 1));
        result += sign * term;
        sign = -sign;
        if (std::abs(term) < epsilon)
        {
            break;
        }
    }
    return result;
}

/***
    Computes the sine of x using Taylor series expansion.
***/
double mySin(double x)
{
    // Sine can be directly calculated using Taylor series
    return x - x * x * x / 6 + x * x * x * x * x / 120 - x * x * x * x * x * x * x / 5040;
}

/***
    Computes the square root of x using binary search.
***/
double mySqrt(double x)
{
    if (x < 0)
    {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    double low = 0;
    double high = x;
    double mid;

    while (high - low > 1e-15)
    {
        mid = (low + high) / 2;
        if (mid * mid > x)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }

    return low;
}

int main()
{
    // Example usage
    cout << "Square root of 25: " << mySqrt(25) << endl;
    cout << "Sine of 0.5: " << mySin(0.5) << endl;
    cout << "Cosine of 0.5: " << myCos(0.5) << endl;
    return 0;
}
