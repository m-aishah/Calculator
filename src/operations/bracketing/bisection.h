#include "../../interfaces/bracketing.h"
#include "../../errors/errors.h"

class bisection : public bracketing
{
    /**
     * findRoots: finds the root of the given equation
     * @equation: the string representation of the mathematical equation to find the root of.
     * @lower: the lower bound for finding the root.
     * @upper: the upper bound for finding the root.
     * @n: number of iterations.
     * Return: the root of @equation between @lower and @upper.
     */
    double findRoots(const std::string& equation, double lower, double upper, const int& n) override
    {
        if (n <= 0) {
            throw std::invalid_argument("Please provide a valid number of iterations");
        }
        double result, evaluatedResult, evaluatedLower;
        for (int i = 0; i < n; i++) {
            result = (lower + upper) / 2;
            evaluatedResult = evaluate(equation, result);
            evaluatedLower = evaluate(equation, lower);
            if ((evaluatedLower * evaluatedResult) > 0)
            lower = result;
            else if ((evaluatedLower * evaluatedResult) < 0)
            upper = result;
            else
            return result;
        }
        return result;
    }

    /**
     * findRoots: finds the root of the given equation
     * @equation: the string representation of the mathematical equation to find the root of.
     * @lower: the lower bound for finding the root.
     * @upper: the upper bound for finding the root.
     * @err: the error percentage to stop if approximate error is less than.
     * Return: the root of @equation between @lower and @upper.
     */
    double findRoots(const std::string& equation, double lower, double upper, const double& err) override
    {
        if (err < 0 || err >= 100) {
            throw std::invalid_argument("Please provide a valid Error Percentage");
        }
        double result, previous, evaluatedResult, evaluatedLower;
        for (double error = 100, int i = 0; error < err;) {
            if(i != 0)
                previous = result;
            result = (lower + upper) / 2;
            evaluatedResult = evaluate(equation, result);
            evaluatedLower = evaluate(equation, lower);
            if ((evaluatedLower * evaluatedResult) > 0)
                lower = result;
            else if ((evaluatedLower * evaluatedResult) < 0)
                upper = result;
            else
                return result;
            if(i != 0)
                error = approximateError(previous, result);
            i++;
        }
        return result;
    }

    public:

    /**
     * operator (): overloads the function call operator. This allows us to use objects of this class as functions.
     * @equation: the string representation of the mathematical equation to find the root of.
     * @lower: the lower bound for finding the root.
     * @upper: the upper bound for finding the root.
     * @n: number of iterations.
     * Return: double 
     */
    double operator()(const std::string& equation, double& lower, double& upper, const int& n)
    {
        return findRoots(equation, lower, upper, n);
    }

    /**
     * operator (): overloads the function call operator. This allows us to use objects of this class as functions.
     * @equation: the string representation of the mathematical equation to find the root of.
     * @lower: the lower bound for finding the root.
     * @upper: the upper bound for finding the root.
     * @err: the error percentage to stop if approximate error is less than.
     * Return: the root of @equation between @lower and @upper
     */
    double operator()(const std::string& equation, double& lower, double& upper, const double& err = 1)
    {
        return findRoots(equation, lower, upper, err);
    }

};