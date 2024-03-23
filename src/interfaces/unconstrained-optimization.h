#include "../handling-equations/equations.h"

class unconstrainedOptimization
{
protected:
    virtual std::tuple<double, double> findMaximum(const std::string &equation, double x0, double x1, double x2, const int maxIter);
    virtual std::tuple<double, double> findMax(const std::string &equation, double xLower, double xUpper, double epsilon, const int maxIter) = 0;

    virtual std::tuple<double, double> findMinimum(const std::string &equation, double x0, double x1, double x2, const int maxIter);
    virtual std::tuple<double, double> findMin(const std::string &equation, double xLower, double xUpper, double epsilon, const int maxIter) = 0;

public:
    virtual ~unconstrainedOptimization(){};
};