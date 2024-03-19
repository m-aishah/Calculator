#include <iostream>
#include <string>
#include "equations.h"

int main()
{
    std::cout << evalExpression("2", 1) << std::endl;
    std::cout << evalExpression("2x", 1) << std::endl;
    std::cout << evalExpression("2.2x", 1) << std::endl;
    std::cout << evalExpression("22log(4.3)", 1) << std::endl;
    std::cout << evalExpression("4log(2x)",  1) << std::endl;
    std::cout << evalExpression("2x", 1) << std::endl;
    std::cout << evalExpression("sin(2sin(log(x)))", 1) << std::endl;
    std::cout << evalExpression("cos(2x)", 1) << std::endl;
    std::cout << evalExpression("tan(2x)", 1) << std::endl;
    std::cout << evalExpression("sec(2x)", 1) << std::endl;
    std::cout << evalExpression("csc(2x)", 1) << std::endl;
    std::cout << evalExpression("cot(2x)", 1) << std::endl;
    std::cout << evalExpression("exp(2x)", 1) << std::endl;
    std::cout << evalExpression("pow(x,2)", 1) << std::endl;
    std::cout << "\n\n\n"
              << std::endl;

    std::cout << formatExpression("2x", 1) << std::endl;
    std::cout << formatExpression("2x+3", 1) << std::endl;
    std::cout << formatExpression("2x-5+7x", 1) << std::endl;
    std::cout << formatExpression("2x+log(2x)", 1) << std::endl;
    std::cout << formatExpression("2x-cot(2x)/3+pow(x,2)", 1) << std::endl;
    std::cout << formatExpression("2x*5y-9.5log(4x)/pow(y,2)*cos(x)", 1) << std::endl;
    std::cout << formatExpression("2x", 1) << std::endl;

    return 0;
}