#include "../../interfaces/open-methods.h"
#include "../../errors/errors.h"

class fixedPoint : protected openMethods
{

    /**
     * findRoots: finds the root of the given equation
     * @equation: the string representation of the mathematical equation to find the root of.
     * @previous: the value of x to start the evaluation with.
     * @n: number of iterations.
     * Return: the root of @equation between @lower and @upper.
     */
    double findRoots(const std::string& equation, const int& n,  double previous, double extra = 0.0) override
    {
        if (n <= 0)
            throw std::invalid_argument("Please provide a valid number of iterations");

        double result;
        for (int i = 0; i < n; i++) 
        {
            if(i != 0)
                previous = result;

            result = evaluate(equation, previous);
        }

        return result;
    }

    /**
     * findRoots: finds the root of the given equation
     * @equation: the string representation of the mathematical equation to find the root of.
     * @previous: the value of x to start the evaluation with.
     * @err: the error percentage to stop if approximate error is less than.
     * Return: the root of @equation between @lower and @upper.
     */
    double findRoots(const std::string& equation, const double& err, double previous, double extra = 0.0) override
    {
        if (err < 0 || err >= 100)
            throw std::invalid_argument("Please provide a valid Error Percentage");
        
        double result;
        for (double error = 100, int i = 0; error < err;) 
        {
            if(i != 0)
                previous = result;

                result = evaluate(equation, previous);
                
            if(i != 0)
                error = approximateError(previous, result);
            i++;
        }

        return result;
    }

    /**
     * operator (): overloads the function call operator. This allows us to use objects of this class as functions.
     * @equation: the string representation of the mathematical equation to find the root of.
     * @x: the value of x to start the evaluation with.
     * @n: number of iterations.
     * Return: double 
     */
    double operator()(const std::string& equation, double& x, const int& n)
    {
        return findRoots(equation, n, x);
    }

    /**
     * operator (): overloads the function call operator. This allows us to use objects of this class as functions.
     * @equation: the string representation of the mathematical equation to find the root of.
     * @x: the value of x to start the evaluation with.
     * @err: the error percentage to stop if approximate error is less than.
     * Return: the root of @equation between @lower and @upper
     */
    double operator()(const std::string& equation, double& x, const double& err = 1)
    {
        return findRoots(equation, err, x);
    }

};