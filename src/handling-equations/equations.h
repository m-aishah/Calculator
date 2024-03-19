#include <iostream>
#include <vector>
#include <string>

std::string parenthesizeExpression(const std::string& exp);
std::string formatExpression(const std::string& exp);

/**
 * isFunction: checks if the given string matches a valid mathematical function
 * @str: the string to check
 * Return: ture if @str is a valid  mathematical function, otherwise false 
 */
bool isFunction(const std::string& str)
{
    if (str == "(log" || str == "(sqrt" || str == "(ln" || str == "(sin" || str == "(cos" || str == "(tan" || 
        str == "(sec" || str == "(csc" || str == "(cot" || str == "(exp" || str == "(pow")
        return true;
    return false;
}


/**
 * parenthesizeExpression: formattes an expression into a form that can be used,
 * putting parentheses around functions, their arguments and variables,
 * as well as adding "*" between numbers and variables or expressions.
 * @exp: the expression to format
 * Return: the formated vesrion of @exp.
 */
double evalExpression(const std::string& exp, double x)
{
    std::string finalExpression = "(";
    std::string temp;
    size_t open = 1;
    // Replace variable with the value of x. Somehow add multiplications(*) if the thing before it is a digit.
    // Handle brackets.
    // Handle decimal numbers
    // Resolve the special functions.
    // Handle regular multiplications like 2x
    // Handle basic numbers like 5 alone.
    // ENsure you consider higher prescedence for operations with brackets? Maybe once you see a bracket just send it to be evaluated. THINK ABOUT THIS!!!
    
    return 1;
}

/**
 * isOperator: Checks if a character is an operator (+, -, /, *).
 * @c: The character to check.
 * Return: true if @c is a character, otherwise false.
 */
bool isOperator(const char &c) { return (c == '+' || c == '-' || c == '/' || c == '*'); }

/**
 * popFront: Removes the first element of a vector.
 * @v: The vector to pop.
 * Return: The first element of the vector (that was removed).
 */
template <class T>
T popFront(std::vector<T> &v)
{
    T f = v[0];
    v.erase(v.begin());
    return f;
}

double evaluateBasicOp (double lOperand, char op, double rOperand)
{
    if (op == '+')
        return lOperand + rOperand;
    else if (op == '-')
        return lOperand - rOperand;
    else if (op =='/')
        return lOperand / rOperand;
    else
        return lOperand * rOperand;

}

/**
 * formatExpression: Converts a string rep. of a mathematical operation,
 * into a form that can be worked with.
 * @ exp - The mathematical expression in question.
 * Return: A properly parenthesized and formatted version of @exp.
 */
double formatExpression(const std::string &exp, double x)
{
    std::vector<double> operands;
    std::vector<char> operators;

    std::string currentOperand;

    // Check that exp is not empty.
    if (exp.empty())
        return 0;

    // Split string into operands and operators and evaluate operands as you go.
    for (auto c : exp)
    {
        if (isOperator(c))
        {
            // Push operator into vector.
            operators.push_back(c);
            // Push operand into appropriate operand vector.
            if (!currentOperand.empty())
            {
                operands.push_back(evalExpression(currentOperand, x));
                currentOperand.clear();
            }
            // Go to the next character.
            continue;
        }
        currentOperand += c;
    }
    // Push the last operand into the vector.
    operands.push_back(evalExpression(currentOperand, x));
    // currentOperand.clear();

    // Assemble final expression.
    double result = popFront(operands);
    double l, o, r;
    // Concatenate the first operand.
    // Interleave operands and operator
    while (!operands.empty())
    {
        // Pop operator, then operand from the front.
        if (!operators.empty())
        {
            l = result;
            o = popFront(operators);
            r = popFront(operands);
            result = evaluateBasicOp(l, o, r);

        }
    }

    return (result);
}