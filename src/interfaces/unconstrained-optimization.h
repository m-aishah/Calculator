#include "../handling-equations/equations.h"

class unconstrainedOptimization
{
protected:
    virtual double findMax(const std::string &equation, double x0, double x1, double x2, const int &n) = 0;

public:
    virtual ~unconstrainedOptimization(){};
};