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
    double findRoots(const std::string& equation, double& lower, double& upper, const int& n) override
    {
        if (n <= 0) {
            throw std::invalid_argument("Please provide a valid number of iterations");
        }
        double result, previous;
        for (int i = 0; i < n; i++) {
            result = (lower + upper) / 2;
            double evaluatedResult = evaluate(equation, result);
            double evaluatedLower = evaluate(equation, lower);
            if ((evaluatedLower * evaluatedResult) > 0)
            lower = result;
            else if ((evaluatedLower * evaluatedResult) < 0)
            upper = result;
            else
            return result;
            previous = result;
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
    double findRoots(const std::string& equation, double& lower, double& upper, const double& err) override
    {
        if (err < 0 || err >= 100) {
            throw std::invalid_argument("Please provide a valid number of iterations");
        }
        double result, previous;
        for (double error = 100; error < err; error = approximateError(previous, result)) {
            result = (lower + upper) / 2;
            double evaluatedresult = evaluate(equation, result);
            double evaluatedLower = evaluate(equation, lower);
            if ((evaluatedLower * evaluatedresult) > 0)
            lower = result;
            else if ((evaluatedLower * evaluatedresult) < 0)
            upper = result;
            else
            return result;
            previous = result;
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