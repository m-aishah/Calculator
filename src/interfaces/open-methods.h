#include "../handling-equations/equations.h"

class openMethods
{
    protected:
    virtual double findRoots(const std::string& equation, const int& n,  double previous, double extra = 0.0) = 0;
    virtual double findRoots(const std::string& equation, const double& err, double previous, double extra = 0.0) = 0;

    public:
    virtual ~openMethods() {};
};