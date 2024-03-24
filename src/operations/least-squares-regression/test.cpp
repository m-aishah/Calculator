#include "linear-regression.h"

int main()
{
    // Example usage:
    std::vector<double> x_values = {1, 2, 3, 4, 5, 6, 7};
    std::vector<double> y_values = {0.5, 2.5, 2.0, 4.0, 3.5, 6.0, 5.5};

    linearRegression lsFit;
    std::pair<double, double> coefficients = lsFit.fitLine(x_values, y_values);

    // Print the coefficients of the fitted line
    std::cout << "a0 = " << coefficients.first << std::endl;
    std::cout << "a1 = " << coefficients.second << std::endl;

    return 0;
}
