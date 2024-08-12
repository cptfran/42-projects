#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include "Colors.hpp"

RPN::RPN()
{

}

RPN::RPN(const RPN& toCopy) : stackRPN(toCopy.stackRPN)
{

}

RPN& RPN::operator=(const RPN& toCopy)
{
    if (this != &toCopy)
    {
        this->stackRPN = toCopy.stackRPN;
    }
    return *this;
}

RPN::~RPN()
{

}

void RPN::calculateResult(const std::string& input)
{
    std::istringstream iss(input);
    if (!isdigit(iss.peek()) && !std::isspace(static_cast<unsigned char>(iss.peek())))
    {
        throw std::invalid_argument("Error: input should start with digit");
    }
    std::string token;
    while (iss >> token)
    {
        if (token.size() == 1 && isdigit(token[0]))
        {
            pushNumberToStack(token);
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            performOperation(token);
        }
        else
        {
            throw std::invalid_argument("Error: found incorrect argument");
        }
    }
    if (this->stackRPN.size() != 1)
    {
        throw std::logic_error("Error: incorrect number of values or operands");
    }
    std::cout << GRAY "Result: " LIGHT_GREEN << this->stackRPN.top() << RESET << std::endl;
}

void RPN::pushNumberToStack(const std::string& token)
{
    const int number = std::stoi(token, NULL, 10);
    if (number < 0 || number >= 10)
    {
        throw std::invalid_argument("Error: number not in range of 0-9");
    }
    this->stackRPN.push(number);
}

void RPN::performOperation(const std::string& token)
{
    if (this->stackRPN.size() < 2)
    {
        throw std::invalid_argument("Error: incorrect number of values or operands");
    }
    const int right_operand = this->stackRPN.top();
    this->stackRPN.pop();
    const int left_operand = this->stackRPN.top();
    this->stackRPN.pop();
    if (token == "+")
    {
        this->stackRPN.push(left_operand + right_operand);
    }
    else if (token == "-")
    {
        this->stackRPN.push(left_operand - right_operand);
    }
    else if (token == "*")
    {
        this->stackRPN.push(left_operand * right_operand);
    }
    else
    {
        this->stackRPN.push(left_operand / right_operand);
    }
}
