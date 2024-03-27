#include <vector>
#include <cmath>
#include "../linear-equations/naive-gauss-elimination.h"
#include "../interfaces/least-squares-regression.h"

class polynomialRegression : public leastSquaresRegression
{
public:
    /**
     * fitPolynomial - Fits a polynomial of degree @degree to the given data points.
     * @xValues: Vector containing x-coordinates.
     * @yValues: Vector containing y-coordinates.
     * @degree: degree of the polynomial.
     * Returns: the coefficients of the fitted polynomial after regression.
     */
    std::vector<double> fitPolynomial(const std::vector<double> &xValues, const std::vector<double> &yValues, int degree) override
    {
        int n = xValues.size();
        int m = degree + 1; // Number of coefficients including constant term

        // Create matrix A and vector b for normal equations
        std::vector<std::vector<double>> A(m, std::vector<double>(m, 0));
        std::vector<double> b(m, 0);

        // Populate matrix A and vector b
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                for (int k = 0; k < n; ++k)
                {
                    A[i][j] += pow(xValues[k], i + j);
                }
            }
            for (int k = 0; k < n; ++k)
            {
                b[i] += pow(xValues[k], i) * yValues[k];
            }
        }

        // Solve the system of linear equations using Gauss elimination
        naiveGaussElimination gaussSolver;
        std::vector<double> coefficients = gaussSolver.solveLinearSystem(A, b);

        // Save coefficients for later use ??
        fittedCoefficients = coefficients;

        return coefficients;
    }

    /**
     * calculateRSquared - Calculates the correlation coefficient (R-squared) of a polynomial.
     * @xValues: Vector containing x-coordinates.
     * @yValues: Vector containing y-coordinates.
     *
     * Returns: the correlation coefficient.
     */
    double calculateRSquared(const std::vector<double> &xValues, const std::vector<double> &yValues) override
    {
        double yMean = calculateMean(yValues);
        double sTotal = calculateTotalSumOfSquares(yValues, yMean);
        double sResidual = calculateResidualSumOfSquares(xValues, yValues);

        return 1.0 - (sResidual / sTotal);
    }

    /**
     * calculateStandardError - Calculate the standard error of the estimate.
     * @xValues: Vector containing x-coordinates.
     * @yValues: Vector containing y-coordinates.
     * Returns: the standard error of estimate.
     */
    double calculateStandardError(const std::vector<double> &xValues, const std::vector<double> &yValues) override
    {
        double sResidual = calculateResidualSumOfSquares(xValues, yValues);
        int n = xValues.size();
        int degree = fittedCoefficients.size() - 1; // Degree of the polynomial
        int dof = n - (degree + 1);                 // Degrees of freedom (Denominator)

        return sqrt(sResidual / dof);
    }

private:
    std::vector<double> fittedCoefficients;

    // Calculate the mean of a vector of values
    double calculateMean(const std::vector<double> &values)
    {
        double sum = 0;
        for (double value : values)
        {
            sum += value;
        }
        return sum / values.size();
    }

    // Calculate the total sum of squares
    double calculateTotalSumOfSquares(const std::vector<double> &yValues, double yMean)
    {
        double sTotal = 0;
        for (double y : yValues)
        {
            sTotal += pow(y - yMean, 2);
        }
        return sTotal;
    }

    // Calculate the residual sum of squares
    double calculateResidualSumOfSquares(const std::vector<double> &xValues, const std::vector<double> &yValues)
    {
        int n = xValues.size();
        double sResidual = 0;
        for (int i = 0; i < n; ++i)
        {
            double yPredicted = 0;
            for (int j = 0; j < fittedCoefficients.size(); ++j)
            {
                yPredicted += fittedCoefficients[j] * pow(xValues[i], j);
            }
            sResidual += pow(yValues[i] - yPredicted, 2);
        }
        return sResidual;
    }
};
