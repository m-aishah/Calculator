#include "../../interfaces/interpolation.h"


class linearInterpolation: public Interpolation
{
    public:  
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

