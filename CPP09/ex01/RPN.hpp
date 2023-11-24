#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>
# include <string>
# include <cstring>

class RPN
{
private:
    std::stack<int> expression;
public:
    RPN();
    RPN(char *str);
    RPN(const RPN &cpy);
    RPN &operator=(const RPN &cpy);
    ~RPN();
    void calculate(char *str, int counter);
};

#endif