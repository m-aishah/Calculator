#include "../../interfaces/least-squares-regression.h"
#include <cmath>

class linearRegression : public leastSquaresRegression
{
public:
    /** fit - Performs least-squares fitting and return the coefficients a0 and a1.
     * @xValues: Vector containing x coordinates.
     * @yValues: Vector containing y coordinates.
     * Returns: the coefficients of a0 and a1.
     */
    std::vector<double> fit(const std::vector<double> &xValues, const std::vector<double> &yValues, int degree = 1) override
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

        std::vector<double> coefficients = {a0, a1};

        // Save coefficients for later use
        fittedCoefficients = coefficients;

        return coefficients;
    }

    /**
     * calculateRSquared - Calculates the coefficient of determination (R^2).
     * @xValues: Vector containing x coordinates.
     * @yValues: Vector containing y coordinates.
     *
     * Returns: The coefficient of determinate (R^2).
     */
    double calculateRSquared(const std::vector<double> &xValues, const std::vector<double> &yValues) override
    {
        int n = xValues.size();

        // Calculate necessary summations
        double yMean = 0;
        for (int i = 0; i < n; ++i)
        {
            yMean += yValues[i];
        }
        yMean /= n;

        double sr = 0, st = 0;
        for (int i = 0; i < n; ++i)
        {
            double yPredicted = fittedCoefficients[0] + fittedCoefficients[1] * xValues[i];
            sr += (yValues[i] - yPredicted) * (yValues[i] - yPredicted);
            st += (yValues[i] - yMean) * (yValues[i] - yMean);
        }

        return 1.0 - (sr / st);
    }

    /**
     * calculateStandardError - Calculate the standard error of estimate (sy/yx)
     * @xValues: Vector containing x coordinates.
     * @yValues: Vector containing y coordinates.
     *
     * Returns: The standard error of estimate.
     */
    double calculateStandardError(const std::vector<double> &xValues, const std::vector<double> &yValues) override
    {
        int n = xValues.size();

        // Calculate necessary summations
        double sr = 0;
        for (int i = 0; i < n; ++i)
        {
            double yPredicted = fittedCoefficients[0] + fittedCoefficients[1] * xValues[i];
            sr += (yValues[i] - yPredicted) * (yValues[i] - yPredicted);
        }

        return sqrt(sr / (n - 2));
    }

private:
    std::vector<double> fittedCoefficients;
};