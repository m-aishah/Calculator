#include "naive-gauss-elimination.h"

int main()
{
    naiveGaussElimination solver;
    std::vector<std::vector<double>> coefficientMatrix = {{99.56, 1, -1}, {-3, -1, 2}, {-2, 1, 2}};
    std::vector<double> constVector = {8, -11, -3};

    std::vector<double> solution = solver.solveLinearSystem(coefficientMatrix, constVector);

    // Print the solution.
    for (int i = 0; i < solution.size(); i++)
    {
        std::cout << "x" << i << " = " << solution[i] << std::endl;
    }

    return 0;
}
