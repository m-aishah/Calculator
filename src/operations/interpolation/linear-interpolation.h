#include "../../interfaces/interpolation.h"


class linearInterpolation: public Interpolation
{
    public:  
        /**
         * interpolationPolation - performs a linear interpolation and returns aproximate
         * @x: interpolation x value
         * @x1: interpolation x1 value
         * @xo:  interpolation xo value
         * @fxo: value of y if xo substituted in the equation
         * @fx1: value of y if xo substituted in the equation
         * Return: interpolation value of y ie fx and excption on failure
        */
        double interpolationData(double x, double x1, double xo, double fxo, double fx1) override
        {
            if ((x - xo) == 0.0)
            {
                throw std::invalid_argument("interpolation interval must not be zero");
            }
            else
            {
                return (fxo + ((fx1 - fxo)/(x1 - xo))*(x - xo));
            }
            
        }
};

