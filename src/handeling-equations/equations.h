#include <iostream>
#include <vector>
#include <string>

std::string parenthesizeExpression(const std::string& exp);
std::string formatExpression(const std::string& exp);

bool isFunction(const std::string& str)
{
    if (str == "(log" || str == "(sqrt" || str == "(ln" || str == "(sin" || str == "(cos" || str == "(tan" || 
        str == "(sec" || str == "(csc" || str == "(cot" || str == "(exp" || str == "(pow")
        return true;
    return false;
}

std::string parenthesizeExpression(const std::string& exp)
{
    std::string finalExpression = "(";
    std::string temp;

    for (char c : exp)
    {
        if (temp.empty())
        {
            if (isdigit(c))
            {
                finalExpression += c;
            }
            else if (isalpha(c))
            {
                if (finalExpression[finalExpression.length() - 1] != '(')
                    finalExpression += "*";
                temp = "(";
                temp += c;
            }
        }
        else
        {
            temp += c;
        }
        if (isFunction(temp))
        {
            finalExpression += temp + "(";
            temp = "";
        }
    }
    temp += ")";
    return finalExpression + temp + ")";
}

