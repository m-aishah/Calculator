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
std::string parenthesizeExpression(const std::string& exp)
{
    std::string finalExpression = "(";
    std::string temp;
    size_t open = 1;

    for (char c : exp)
    {
        if (c == '(')
            open++;
        if (c == ')')
            open--;
        if (temp.empty())
        {
            if (isdigit(c) || c == '.')
            {
                finalExpression += c;
            }
            else if (isalpha(c))
            {
                if (finalExpression.back() != '(')
                {
                    finalExpression += "*(";
                    open++;
                }
                temp += c;
            }
        }
        else
        {
            if (isdigit(temp.back()) && !isdigit(c) && c != '.' && c != ')')
            {
                temp += "*(";
                open++;
            }
            temp += c;
        }
        if (isFunction(temp))
        {
            finalExpression += temp + "(";
            open++;
            temp = "";
        }
    }
    finalExpression += temp;
    while (open > 0)
    {
        finalExpression += ")";
        open--;
    }
    return finalExpression;
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

/**
 * formatExpression: Converts a string rep. of a mathematical operation,
 * into a form that can be worked with.
 * @ exp - The mathematical expression in question.
 * Return: A properly parenthesized and formatted version of @exp.
 */
std::string formatExpression(const std::string &exp)
{
    std::vector<std::string> operands;
    std::vector<char> operators;

    std::string currentOperand;

    // Check that exp is not empty.
    if (exp.empty())
        return NULL;

    // Split string into operands and operators and parenthesize operands.
    for (auto c : exp)
    {
        if (isOperator(c))
        {
            // Push operator into vector.
            operators.push_back(c);
            // Push operand into appropriate operand vector.
            if (!currentOperand.empty())
            {
                operands.push_back(parenthesizeExpression(currentOperand));
                currentOperand.clear();
            }
            // Go to the next character.
            continue;
        }
        currentOperand += c;
    }
    // Push the last operand into the vector.
    operands.push_back(parenthesizeExpression(currentOperand));
    // currentOperand.clear();

    // Assemble final expression.
    std::string finalExpression = "(";
    // Concatenate the first operand.
    finalExpression += popFront(operands);
    // Interleave operands and operator
    while (!operands.empty())
    {
        // Pop operator, then operand from the front.
        if (!operators.empty())
            finalExpression += popFront(operators);
        finalExpression += popFront(operands);
    }
    // Add final parenthesis.
    finalExpression += ")";

    return (finalExpression);
}