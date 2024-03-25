#include "linear-interpolation.h"

int main()
{
    linearInterpolation test;
    double fxo = 0.0, fx1 = 1.791759, x = 2.0, x1 = 6.0, xo = 1.0;

    std::cout << "-----------Welcome to the world of linear interpolation-------" << std::endl;
    /*Estimate the natural logarithm of 2 using linear interpolation. 
    First, perform the computation by interpolating between ln 1 5 0 and ln 6 5 1.791759. 
    Then, repeat the procedure, but use a smaller interval from ln 1 to ln 4 (1.386294). Note 
    that the true value of ln 2 is 0.6931472*/
    auto fx = test.interpolationData(x, x1, xo, fxo, fx1);
    std::cout << "-----------first interval-------" << std::endl;
    // second interval to be implemented
    std::cout << "The natural logarithm of 2 is " << fx << std::endl;

}