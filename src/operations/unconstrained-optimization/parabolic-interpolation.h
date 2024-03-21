#include "../../interfaces/unconstrained-optimization.h"

class parabolicInterpolation : public unconstrainedOptimization
{

    /**
     * findMax - Finds the maximum point of a given function.
     * @equation: String representation of the mathematical equation of the function in question.
     * @x0: x value of the first coordinate.
     * @x1: x value of the second coordinate.
     * @x2: x value of the third coordinate.
     * @n: Number of iterations.
     * Returns: the maximum point of the provided @equation.
     */
    double findMax(const std::string &equation, double x0, double x1, double x2, const int &n) override
    {
        if (n <= 0)
            throw std::invalid_argument("Please provide a valid number of iterations");

        double x3, fx0, fx1, fx2, result = 0.0;
        for (int i = 0; i < n; i++)
        {
            fx0 = evaluate(equation, x0);
            fx1 = evaluate(equation, x1);
            fx2 = evaluate(equation, x2);

            double denominator = 2 * ((fx0 * (x1 - x2)) + (fx1 * (x2 - x0)) + (fx2 * (x0 - x1)));
            if (denominator == 0.0) // Handle division by zero.
                throw std::runtime_error("Division by zero encountered");
            x3 = ((fx0 * (pow(x1, 2) - pow(x2, 2))) +
                  (fx1 * (pow(x2, 2) - pow(x0, 2))) +
                  (fx2 * (pow(x0, 2) - pow(x1, 2)))) /
                 denominator;

            // Update variables.
            x2 = (x1 > x3) ? x1 : x2;
            x0 = (x2 == x1) ? x0 : x1;
            x1 = x3;
            result = evaluate(equation, x3);
        }

        return result;
    }

public:
    /**
     * operator (): overloads the function call operator. This allows us to use objects of this class as functions.
     * @x0: x value of the first coordinate.
     * @x1: x value of the second coordinate.
     * @x2: x value of the third coordinate.
     * @n: Number of iterations.
     */
    double operator()(const std::string &equation, double &x0, double &x1, double &x2, const int &n)
    {
        return findMax(equation, x0, x1, x2, n);
    }
};