#include "linear-regression.h"

void testLinearRegression()
{
    // Sample data points
    std::vector<double> xValues = {1, 2, 3, 4, 5, 6, 7};
    std::vector<double> yValues = {0.5, 2.5, 2.0, 4.0, 3.5, 6.0, 5.5};

    linearRegression linRegression;

    // Fit a linear regression line
    std::vector<double> coefficients = linRegression.fit(xValues, yValues);

    // Output the coefficients of the fitted line
    std::cout << "\nFitted Line Coefficients:" << std::endl;
    std::cout << "a0: " << coefficients[0] << std::endl;
    std::cout << "a1: " << coefficients[1] << std::endl;

    // Calculate R-squared
    double rSquared = linRegression.calculateRSquared(xValues, yValues);
    std::cout << "\nCoefficient of Determination (R-squared): " << rSquared << std::endl;

    // Calculate the standard error of the estimate
    double standardError = linRegression.calculateStandardError(xValues, yValues);
    std::cout << "Standard Error of the Estimate: " << standardError << std::endl;
}

int main()
{

    std::cout << "\nTesting Linear Regression:" << std::endl;
    testLinearRegression();

    return 0;
}