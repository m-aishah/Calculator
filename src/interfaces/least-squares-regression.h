#include "../handling-equations/equations.h"

class leastSquaresRegression
{
protected:
    virtual std::vector<double> fitLine(const std::vector<double> &xValues, const std::vector<double> &yValues) = 0;
    virtual std::vector<double> fitPolynomial(const std::vector<double> &xValues, const std::vector<double> &yValues, int degree) = 0;

    virtual double calculateRSquared(const std::vector<double> &xValues, const std::vector<double> &yValues) = 0;
    virtual double calculateStandardError(const std::vector<double> &xValues, const std::vector<double> &yValues) = 0;

public:
    virtual ~leastSquaresRegression(){};
};