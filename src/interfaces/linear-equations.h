#include "../handling-equations/equations.h"

class linearEquations
{
protected:
    virtual std::vector<double> solveLinearSystem(std::vector<std::vector<double>> &coefficientMatrix, const std::vector<double> &constVector) = 0;

public:
    virtual ~linearEquations(){};
};