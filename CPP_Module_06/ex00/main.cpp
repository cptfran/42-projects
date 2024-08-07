#include <iostream>
#include "ScalarConverter.hpp"
#include "Colors.hpp"

int main(const int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << RED "Error: run program with one argument" RESET << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}