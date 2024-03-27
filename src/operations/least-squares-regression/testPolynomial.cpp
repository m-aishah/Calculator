#include <iostream>
#include <vector>
#include "polynomial-regression.h"

void testPolynomialRegression()
{
    // Sample data points
    std::vector<double> xValues = {0, 1, 2, 3, 4, 5};
    std::vector<double> yValues = {2.1, 7.7, 13.6, 27.2, 40.9, 61.1};

    polynomialRegression polyRegression;

    // Fit a second-order polynomial
    int degree = 2;
    std::vector<double> coefficients = polyRegression.fitPolynomial(xValues, yValues, degree);

    // Output the coefficients of the fitted polynomial
    std::cout << "Fitted Polynomial Coefficients:" << std::endl;
    for (int i = 0; i <= degree; ++i)
    {
        std::cout << "a" << i << ": " << coefficients[i] << std::endl;
    }

    // Calculate R-squared
    double rSquared = polyRegression.calculateRSquared(xValues, yValues);
    std::cout << "\nCoefficient of Determination (R-squared): " << rSquared << std::endl;

    // Calculate the standard error of the estimate
    double standardError = polyRegression.calculateStandardError(xValues, yValues);
    std::cout << "Standard Error of the Estimate: " << standardError << std::endl;
}

int main()
{
    std::cout << "Testing Polynomial Regression:" << std::endl;
    testPolynomialRegression();

    return 0;
}