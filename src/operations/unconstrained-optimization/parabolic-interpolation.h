#include "../../interfaces/unconstrained-optimization.h"

class parabolicInterpolation : public unconstrainedOptimization
{
    /**
     * findMaxMin - Finds the maximum/minimum point of a given function.
     * @equation: String representation of the mathematical equation of the function in question.
     * @x0: x value of the first coordinate.
     * @x1: x value of the second coordinate.
     * @x2: x value of the third coordinate.
     * @maxIter: Number of iterations.
     * @findMax: Serves as a flag to indicate weather to find maximum or minimum.
     * Returns: the maximum/minimum point of the provided @equation.
     */
    std::tuple<double, double> findMaxMin(const std::string &equation, double x0, double x1, double x2, const int maxIter, bool findMax)
    {
        if (maxIter <= 0)
            throw std::invalid_argument("Please provide a valid number of iterations");

        double x3, f0, f1, f2, fOptimum = 0.0;
        for (int i = 0; i < maxIter; i++)
        {
            f0 = evaluate(equation, x0);
            f1 = evaluate(equation, x1);
            f2 = evaluate(equation, x2);

            double denominator = 2 * ((f0 * (x1 - x2)) + (f1 * (x2 - x0)) + (f2 * (x0 - x1)));
            if (denominator == 0.0) // Handle division by zero.
                throw std::runtime_error("Division by zero encountered");
            x3 = ((f0 * (pow(x1, 2) - pow(x2, 2))) +
                  (f1 * (pow(x2, 2) - pow(x0, 2))) +
                  (f2 * (pow(x0, 2) - pow(x1, 2)))) /
                 denominator;

            // Update variables.
            if (findMax)
            {
                x2 = (x1 > x3) ? x1 : x2;
                x0 = (x2 == x1) ? x0 : x1;
                x1 = x3;
                fOptimum = evaluate(equation, x3);
            }
            else
            {
                x2 = (x1 < x3) ? x1 : x2;
                x0 = (x2 == x1) ? x0 : x1;
                x1 = x3;
                fOptimum = evaluate(equation, x3);
            }
        }

        return std::make_tuple(x3, fOptimum);
    }

public:
    /**
     * findMaximum - Finds the maximum point of a given function.
     * @equation: String representation of the mathematical equation of the function in question.
     * @x0: x value of the first coordinate.
     * @x1: x value of the second coordinate.
     * @x2: x value of the third coordinate.
     * @maxIter: Number of iterations.
     * Returns: the maximum point of the provided @equation.
     */
    std::tuple<double, double> findMaximum(const std::string &equation, double x0, double x1, double x2, const int maxIter) override
    {
        return findMaxMin(equation, x0, x1, x2, maxIter, true);
    }

    /**
     * findMinimum - Finds the minimum point of a given function.
     * @equation: String representation of the mathematical equation of the function in question.
     * @x0: x value of the first coordinate.
     * @x1: x value of the second coordinate.
     * @x2: x value of the third coordinate.
     * @maxIter: Number of iterations.
     * Returns: the minimum point of the provided @equation.
     */
    std::tuple<double, double> findMinimum(const std::string &equation, double x0, double x1, double x2, const int maxIter) override
    {
        return findMaxMin(equation, x0, x1, x2, maxIter, false);
    }
};