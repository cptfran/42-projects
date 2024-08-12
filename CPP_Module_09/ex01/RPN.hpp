#ifndef RPN_HPP
#define RPN_HPP
#include <stack>

class RPN
{
public:
    RPN();
    RPN(const RPN& toCopy);
    RPN& operator=(const RPN& toCopy);
    ~RPN();
    void calculateResult(const std::string& input);
    void pushNumberToStack(const std::string& token);
    void performOperation(const std::string& token);
private:
    std::stack<int> stackRPN;
};

#endif