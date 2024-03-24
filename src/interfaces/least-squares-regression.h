#include "../handling-equations/equations.h"

class leastSquaresRegression
{
protected:
    virtual std::pair<double, double> fitLine(const std::vector<double> &xValues, const std::vector<double> &yValues) = 0;

public:
    virtual ~leastSquaresRegression(){};
};