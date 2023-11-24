#include "RPN.hpp"

RPN::RPN()
{
}

void RPN::calculate(char *str ,int counter)
{
    int num1;
    int num2;
    int i = counter;

    while(str[i] && expression.size() > 1)
    {
        if(str[i] == '*')
        {
            num1 = expression.top();
            expression.pop();
            num2 = expression.top();
            expression.pop();
            expression.push(num2 * num1);
        }
        else if(str[i] == '/')
        {
            num1 = expression.top();
            expression.pop();
            num2 = expression.top();
            if (num1 == 0)
            {
                std::cerr << "Division by zero impossible, operation skipped" << std::endl;
                return;
            }
            expression.pop();
            expression.push(num2 / num1);
        }
        else if(str[i] == '+')
        {
            num1 = expression.top();
            expression.pop();
            num2 = expression.top();
            expression.pop();
            expression.push(num2 + num1);
        }
        else if(str[i] == '-')
        {
            num1 = expression.top();
            expression.pop();
            num2 = expression.top();
            expression.pop();
            expression.push(num2 - num1);
        }
        i++;
    }
}

RPN::RPN(char *str)
{
    int i = 0;

    while(str[i])
    {
        if(isdigit(str[i]) == 0 && str[i] != ' ' && str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/')
        {
            std::cerr << "Something's wrong in the expression" << std::endl;
            return ;
        }
        i++;
    }
    i = 0;
    while(str[i])
    {
        if(isdigit(str[i]) != 0)
        {
            expression.push(str[i] - 48);
        }
        if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            calculate(str, i);
        }
        i++;
    }
    std::cout << expression.top() << std::endl;
}

RPN::RPN(const RPN &cpy)
{
    *this = cpy;
}

RPN &RPN::operator=(const RPN &cpy)
{
    this->expression = cpy.expression;
    return *this;
}

RPN::~RPN()
{
}
