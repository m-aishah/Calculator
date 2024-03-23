#include "../../interfaces/unconstrained-optimization.h"

class goldenSectionSearch : public unconstrainedOptimization
{
private:
    // The golden Ratio.
    const double R = (std::sqrt(5) - 1) / 2;

    /**
     * findMax - Finds the maximum point of a given function.
     * @equation: String representation of the mathematical equation of the function in question.
     * @xLower: Lower bound of the search interval.
     * @xUpper: Upper bound of the search interval.
     * @epsilon: Error tolerance.
     * @maxIter: Maximum number of iterations.
     * Returns: the x and y coordinates of the maximum point of the provided @equation.
     */
    std::tuple<double, double> findMax(const std::string &equation, double xLower, double xUpper, double epsilon, const int maxIter) override
    {
        if (maxIter <= 0)
            throw std::invalid_argument("Please provide a valid number of iterations");

        double x1, x2, f1, f2, d, absError, xInterval, xMax, fMax;
        int i = 1;
        d = R * (xUpper - xLower);
        x1 = xLower + d;
        x2 = xUpper - d;

        f1 = evaluate(equation, x1);
        f2 = evaluate(equation, x2);

        xMax = (f1 > f2) ? x1 : x2;
        fMax = (f1 > f2) ? f1 : f2;

        do
        {
            d *= R;
            xInterval = xUpper - xLower;
            if (f1 > f2)
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
            xMax = (f1 > f2) ? x1 : x2;
            fMax = (f1 > f2) ? f1 : f2;

            if (xMax != 0.0)
                absError = (1.0 - R) * std::abs(xInterval / xMax) * 100.0;

        } while (absError > epsilon && i < maxIter);

        // return xMax
        return std::make_tuple(xMax, fMax);
    }

    /**
     * findMin - Finds the minimum point of a given function.
     * @equation: String representation of the mathematical equation of the function in question.
     * @xLower: Lower bound of the search interval.
     * @xUpper: Upper bound of the search interval.
     * @epsilon: Error tolerance.
     * @maxIter: Maximum number of iterations.
     * Returns: the x and y coordinates of the minimum point of the provided @equation.
     */
    std::tuple<double, double> findMin(const std::string &equation, double xLower, double xUpper, double epsilon, const int maxIter) override
    {
        if (maxIter <= 0)
            throw std::invalid_argument("Please provide a valid number of iterations");

        double x1, x2, f1, f2, d, absError, xInterval, xMin, fMin;
        int i = 1;
        d = R * (xUpper - xLower);
        x1 = xLower + d;
        x2 = xUpper - d;

        f1 = evaluate(equation, x1);
        f2 = evaluate(equation, x2);

        xMin = (f1 < f2) ? x1 : x2;
        fMin = (f1 < f2) ? f1 : f2;

        do
        {
            d *= R;
            xInterval = xUpper - xLower;
            if (f1 < f2)
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
            xMin = (f1 < f2) ? x1 : x2;
            fMin = (f1 < f2) ? f1 : f2;

            if (xMin != 0.0)
                absError = (1.0 - R) * abs(xInterval / xMin) * 100.0;

        } while (absError > epsilon && i < maxIter);

        // return xMin
        return std::make_tuple(xMin, fMin);
    }
};