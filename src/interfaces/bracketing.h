#include "../handling-equations/equations.h"

class bracketing
{
    protected:
    virtual double findRoots(const std::string& equation, double& lower, double& upper, const int& n) = 0;
    virtual double findRoots(const std::string& equation, double& lower, double& upper, const double& err) = 0;

    public:
    virtual ~bracketing() {};
};