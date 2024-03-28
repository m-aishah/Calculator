#include "../handling-equations/equations.h"

class Interpolation 
{
    //public:
        virtual double linearData(double x,double x0,double x1,double fx0,double fx1) = 0;
        virtual double quadraticData(double x,double x0 ,double x1 ,double x2 ,double fx0 ,double fx1 ,double fx2) = 0;
        //~Interpolation() {};

};