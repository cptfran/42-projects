#include <iostream>
#include "Colors.hpp"
#include "RPN.hpp"

int main(const int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << RED "Error: incorrect number of arguments\n" LIGHT_CYAN "Usage: ./RPN \"input\"" RESET << std::endl;
        return 2;
    }
    try
    {
        RPN RPN;
        const std::string input = argv[1];
        RPN.calculateResult(input);
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    catch (const std::logic_error& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    return 0;
}
