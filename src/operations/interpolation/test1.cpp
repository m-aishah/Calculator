
//include "quadratic-interpolation.h"
#include "linear-interpolation.h"
#include <iomanip>
int main()
{
    linearInterpolation test1;
    linearInterpolation test2;
    //QuadraticInterpolation test2;
    //QuadraticInterpolation test2;
    double fxo = 0.0, fx1 = 1.386294,x = 2.0,x1 = 4.0,x0 = 1.0,fx2 = 1.791759,x2 = 6.0;

    std::cout << "-----------Welcome to the world of linear interpolation-------" << std::endl;
    /*Estimate the natural logarithm of 2 using linear interpolation. 
    First, perform the computation by interpolating between ln 1 5 0 and ln 6 5 1.791759. 
    Then, repeat the procedure, but use a smaller interval from ln 1 to ln 4 (1.386294). Note 
    that the true value of ln 2 is 0.6931472*/
    auto fx = test1.linearData(x, x0, x1, fxo, fx1);
    std::cout <<std::setprecision(9)<< "-----------first interval-------" << fx <<std::endl;
    // second interval to be implemented
    
    auto y = test2.quadraticData(x, x0, x1,x2 ,fxo, fx1,fx2);
    std::cout << "Using quadratic interpolation " << y << std::endl;



}