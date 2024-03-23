#include "../../interfaces/linear-equations.h"

class naiveGaussElimination : public linearEquations
{
public:
    /**
     * SolveLinearSystem - solves a system of linear equations using the Naive Gaussian elimination.
     * @coefficientMatrix: Matrix of coefficients of the linear system.
     * @constVector: Vector of constant values in the equations.
     * Returns: The solution vector.
     */
    std::vector<double> solveLinearSystem(std::vector<std::vector<double>> &coefficientMatrix, const std::vector<double> &constVector) override
    {
        int n = coefficientMatrix.size();
        std::vector<std::vector<double>> augMatrix(n, std::vector<double>(n + 1));

        // Combine coefficientMatrix and constVector into augMatrix.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                augMatrix[i][j] = coefficientMatrix[i][j];
            }
            augMatrix[i][n] = constVector[i];
        }

        // Forward Elimination.
        for (int k = 0; k < n; k++)
        {
            for (int i = k + 1; i < n; i++)
            {
                double factor = augMatrix[i][k] / augMatrix[k][k];
                for (int j = k; j < n + 1; j++)
                {
                    augMatrix[i][j] -= factor * augMatrix[k][j];
                }
            }
        }

        // Back Substitution.
        std::vector<double> x(n);
        x[n - 1] = augMatrix[n - 1][n] / augMatrix[n - 1][n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            double sum = augMatrix[i][n];
            for (int j = i + 1; j < n; j++)
            {
                sum -= augMatrix[i][j] * x[j];
            }
            x[i] = sum / augMatrix[i][i];
        }

        return x;
    }
};