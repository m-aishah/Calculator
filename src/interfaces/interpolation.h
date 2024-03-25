#include "../handling-equations/equations.h"

class Interpolation 
{
    public:
        virtual double interpolationData(double x, double x1, double xo, double fxo, double fx1)=0;
        ~Interpolation() {};

};