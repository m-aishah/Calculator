#include "../../interfaces/least-squares-regression.h"

class linearRegression : public leastSquaresRegression
{
public:
    /** fitLine - Performs least-squares fitting and return the coefficients a0 and a1.
     * @xValues: Vector containing x coordinates.
     * @yValues: Vector containing y coordinates.
     * Returns: the coefficients of a0 and a1.
     */
    std::pair<double, double> fitLine(const std::vector<double> &xValues, const std::vector<double> &yValues)
    {
        int n = xValues.size();

        // Calculate necessary summations
        double xSum = 0, ySum = 0, xySum = 0, xSum_squared = 0;
        for (int i = 0; i < n; ++i)
        {
            xSum += xValues[i];
            ySum += yValues[i];
            xySum += xValues[i] * yValues[i];
            xSum_squared += xValues[i] * xValues[i];
        }

        // Calculate means
        double xMean = xSum / n;
        double yMean = ySum / n;

        // Calculate coefficients a0 and a1
        double a1 = (n * xySum - xSum * ySum) / (n * xSum_squared - xSum * xSum);
        double a0 = yMean - a1 * xMean;

        return std::make_pair(a0, a1);
    }
};