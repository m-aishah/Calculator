#include "../../interfaces/interpolation.h"

class linearInterpolation: public Interpolation
{
    private:
        double b0,b1 ,b2 ;
        double fx1x0, fx2x1, fx3x2, fx2x1x0, fx3x2x1, fx3x2x1x0;
    public:  
        /**
         * interpolationPolation - performs a linear interpolation and returns aproximate
         * @x: interpolation x value
         * @x1: interpolation x1 value
         * @x0:  interpolation xo value
         * @fx0: value of y if xo substituted in the equation
         * @fx1: value of y if xo substituted in the equation
         * Return: interpolation value of y ie fx and excption on failure
        */
        double linearData(double x,double x0,double x1,double fx0,double fx1) override 
        {
            if ((x - x0) == 0.0)
            {
                throw std::invalid_argument("interpolation interval must not be zero");
            }
            else
            {
                return (fx0 + ((fx1 - fx0)/(x1 - x0))*(x - x0));
            }
            
        }
        

        /**
         * interpolationPolation - performs a linear interpolation and returns aproximate
         * @x: interpolation x value
         * @x1: interpolation x1 value
         * @x0:  interpolation xo value
         * @x2: interpolation x2 value
         * @fx0: interpolation fx0 value 
         * @fx1: interpolation fx1 value
         * @fx2: interpolation fx2 value
         * Return: interpolation value of y if xo substituted in the equation 
         */
        double quadraticData(double x,double x0,double x1,double x2,double fx0,double fx1,double fx2) override
        {
            if ((x1 - x0 == 0.0) || (x2 - x0 == 0.0))
            {
                throw std::invalid_argument("devision by zero!!!");
            }

            b1 = (fx1 - fx0) / (x1 - x0);
            std::cout <<"b1=\t"<<b1 << std::endl;
            b2 = ((fx2 - fx1) / (x2 - x1) - b1) / (x2 - x0);
            std::cout <<"b2=\t"<< b2<< std::endl;
            return (b0 + b1 * (x - x0) + b2 * (x - x0) * (x - x1));
        }
        

        /**
         * newonData - calculates fx using Newton’s Interpolating Polynomials
         * Return: estimate value of fx
        */
        double newtonData(double x, double x0, double x1, double x2, double x3,double fx0, double fx1, double fx2, double fx3)
        {
            if (x1 - x0 == 0.0)
            {
                throw std::invalid_argument("Devision by zero in (x1 - x0) !");
            }
            fx1x0 = (fx1 - fx0) / (x1 - x0);
            std::cout<< "fx1x0:"<< fx1x0 << std::endl;

            if (x2 - x1 == 0.0)
            {
                throw std::invalid_argument("Devision by zero in (x2 - x1) !");
            }
            fx2x1 = (fx2 - fx1) / (x2 - x1);
            std::cout<< "fx2x1:"<< fx2x1 << std::endl;

            if (x3 - x2 == 0.0)
            {
                throw std::invalid_argument("Devision by zero in (x3 - x2) !");
            }
            fx3x2 = (fx3 - fx2) / (x3 - x2);
            std::cout<< "fx3x2:"<< fx3x2 << std::endl;

            if (x2 - x0 == 0.0)
            {
                throw std::invalid_argument("Devision by zero in (x2 - x0) !");
            }
            fx2x1x0 = (fx2x1 - fx1x0) / (x2 - x0);
            std::cout<< "fx2x1x0:"<< fx2x1x0 << std::endl;

            if (x3 - x1 == 0.0)  
            {
                throw std::invalid_argument("Devision by zero in (x3 - x1) !");
            }
            fx3x2x1 = (fx3x2 - fx2x1) / (x3 - x1);
            std::cout<< "fx3x2x1:"<< fx3x2x1 << std::endl;

             if (x3 - x0 == 0.0)
             {
                 throw std::invalid_argument("Devision by zero in (x3 - x0) !");
             }
            fx3x2x1x0 = (fx3x2x1 - fx2x1x0) / (x3 - x0);
            std::cout<< "fx3x2x1x0:"<< fx3x2x1x0 << std::endl;
    

            return (fx0 + fx1x0 * (x - x0) + fx2x1x0 * (x - x0) * (x - x1) + fx3x2x1x0 * (x - x0) * (x - x1) * (x - x2) );
        }
        void reset() noexcept
        {
            b0 = 0.0;
            b1 = 0.0;
            b2 = 0.0;
        }
};

