#include "ScalarConverter.hpp"
#include "Colors.hpp"
#include <cstdlib>
#include <iostream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& val)
{
//      1 - type is char, 2 - type is int, 3 - type is float, 4 - type is double, -1 - not printable char,
//      2 - out of range or not handled char
    int type = verifyType(val);
    switch (type)
    {
        case 1:
            printFromChar(val[0]);
            break;
        case 2:
            printFromInt(std::atoi(val.c_str()));
            break;
        case 3:
            char *endFloat;
            printFromFloat(std::strtof(val.c_str(), &endFloat));
            break;
        case 4:
            char *endDouble;
            printFromDouble(std::strtod(val.c_str(), &endDouble));
            break;
        case -1:
            std::cerr << RED "Error: found not printable char" RESET << std::endl;
            break;
        case -2:
            std::cerr << RED "Error: value is out of range or format is wrong" RESET << std::endl;
            break;
        default:
            std::cerr << RED "Something went wrong, try again" RESET << std::endl;
    }
}