#include "../../interfaces/unconstrained-optimization.h"

class goldenSectionSearch : public unconstrainedOptimization
{
private:
    // The golden Ratio.
    const double R = (std::sqrt(5) - 1) / 2;

    /**
     * findMax - Finds the maximum/minimum point of a given function.
     * @equation: String representation of the mathematical equation of the function in question.
     * @xLower: Lower bound of the search interval.
     * @xUpper: Upper bound of the search interval.
     * @epsilon: Error tolerance.
     * @maxIter: Maximum number of iterations.
     * @findMax: A flag that indicates whether to find the maximum or minimum.
     * Returns: the x and y coordinates of the maximum/minimum point of the provided @equation.
     */
    std::tuple<double, double> findMaxMin(const std::string &equation, double xLower, double xUpper, double epsilon, const int maxIter, bool findMax)
    {
        if (maxIter <= 0)
            throw std::invalid_argument("Please provide a valid number of iterations");

        double x1, x2, f1, f2, d, absError, xInterval, xOptimum, fOptimum;
        int i = 1;
        d = R * (xUpper - xLower);
        x1 = xLower + d;
        x2 = xUpper - d;

        f1 = evaluate(equation, x1);
        f2 = evaluate(equation, x2);

        if (findMax)
        {
            xOptimum = (f1 > f2) ? x1 : x2;
            fOptimum = (f1 > f2) ? f1 : f2;
        }
        else
        {
            xOptimum = (f1 < f2) ? x1 : x2;
            fOptimum = (f1 < f2) ? f1 : f2;
        }

        do
        {
            d *= R;
            xInterval = xUpper - xLower;
            if (findMax ? (f1 > f2) : (f1 < f2))
            {
                xLower = x2;
                x2 = x1;
                x1 = xLower + d;
                f2 = f1;
                f1 = evaluate(equation, x1);
            }
            else
            {
                xUpper = x1;
                x1 = x2;
                x2 = xUpper - d;
                f1 = f2;
                f2 = evaluate(equation, x2);
            }
            i++;

            if (findMax)
            {
                xOptimum = (f1 > f2) ? x1 : x2;
                fOptimum = (f1 > f2) ? f1 : f2;
            }
            else
            {
                xOptimum = (f1 < f2) ? x1 : x2;
                fOptimum = (f1 < f2) ? f1 : f2;
            }

            if (xOptimum != 0.0)
                absError = (1.0 - R) * std::abs(xInterval / xOptimum) * 100.0;

        } while (absError > epsilon && i < maxIter);

        return std::make_tuple(xOptimum, fOptimum);
    }

public:
    /**
     * findMaximum - Finds the maximum point of a given function.
     * @equation: String representation of the mathematical equation of the function in question.
     * @xLower: Lower bound of the search interval.
     * @xUpper: Upper bound of the search interval.
     * @epsilon: Error tolerance.
     * @maxIter: Maximum number of iterations.
     * Returns: the x and y coordinates of the maximum point of the provided @equation.
     */
    std::tuple<double, double> findMaximum(const std::string &equation, double xLower, double xUpper, double epsilon, int maxIter) override
    {
        return findMaxMin(equation, xLower, xUpper, epsilon, maxIter, true);
    }

    /**
     * findMinimum - Finds the maximum/minimum point of a given function.
     * @equation: String representation of the mathematical equation of the function in question.
     * @xLower: Lower bound of the search interval.
     * @xUpper: Upper bound of the search interval.
     * @epsilon: Error tolerance.
     * @maxIter: Maximum number of iterations.
     * Returns: the x and y coordinates of the minimum point of the provided @equation.
     */
    std::tuple<double, double> findMaximum(const std::string &equation, double xLower, double xUpper, double epsilon, int maxIter) override
    {
        return findMaxMin(equation, xLower, xUpper, epsilon, maxIter, false);
    }
};