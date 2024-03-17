#include <iostream>
#include <string>
#include "finding-roots.h"

int main()
{
    std::cout << parenthesizeExpression("2") << std::endl;
    std::cout << parenthesizeExpression("2x") << std::endl;
    std::cout << parenthesizeExpression("2.2x") << std::endl;
    std::cout << parenthesizeExpression("22log(4.3)") << std::endl;
    std::cout << parenthesizeExpression("4log(2x)") << std::endl;
    std::cout << parenthesizeExpression("2x") << std::endl;
    std::cout << parenthesizeExpression("sin(2sin(log(x)))") << std::endl;
    std::cout << parenthesizeExpression("cos(2x)") << std::endl;
    std::cout << parenthesizeExpression("tan(2x)") << std::endl;
    std::cout << parenthesizeExpression("sec(2x)") << std::endl;
    std::cout << parenthesizeExpression("csc(2x)") << std::endl;
    std::cout << parenthesizeExpression("cot(2x)") << std::endl;
    std::cout << parenthesizeExpression("exp(2x)") << std::endl;
    std::cout << parenthesizeExpression("pow(x,2)") << std::endl;
    std::cout << "\n\n\n"
              << std::endl;

    std::cout << formatExpression("2x") << std::endl;
    std::cout << formatExpression("2x+3") << std::endl;
    std::cout << formatExpression("2x-5+7x") << std::endl;
    std::cout << formatExpression("2x+log(2x)") << std::endl;
    std::cout << formatExpression("2x-cot(2x)/3+pow(x,2)") << std::endl;
    std::cout << formatExpression("2x*5y-9.5log(4x)/pow(y,2)*cos(x)") << std::endl;
    std::cout << formatExpression("2x") << std::endl;

    return 0;
}