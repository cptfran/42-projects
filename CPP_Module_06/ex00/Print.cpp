#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

void printFromChar(char valAsChar)
{
    std::cout << "char: " << valAsChar << "\nint: " << static_cast<int>(valAsChar) << std::fixed
              << std::setprecision(1) << "\nfloat: " << static_cast<float>(valAsChar) << "f\ndouble: "
              << static_cast<double>(valAsChar) << std::endl;
}

void printFromInt(int valAsInt)
{
    if (isNumInCharRange(valAsInt))
    {
        if (std::isprint(valAsInt))
        {
            std::cout << "char: " << static_cast<char>(valAsInt) << std::endl;
        }
        else
        {
            std::cout << "char: Non displayable" << std::endl;
        }
    }
    else
    {
        std::cout << "char: impossible" << std::endl;
    }
    std::cout << "int: " << valAsInt << std::fixed << std::setprecision(1) << "\nfloat: "
              << static_cast<float>(valAsInt) << "f\ndouble: " << static_cast<double>(valAsInt) << std::endl;
}

void printFromFloat(float valAsFloat)
{
    if (isNumInIntRange(valAsFloat))
    {
        if (isNumInCharRange(valAsFloat))
        {
            if (std::isprint(static_cast<int>(valAsFloat)))
            {
                std::cout << "char: " << static_cast<char>(valAsFloat) << std::endl;
            }
            else
            {
                std::cout << "char: Non displayable" << std::endl;
            }
        }
        else
        {
            std::cout << "char: impossible" << std::endl;
        }
        std::cout << "int: " << static_cast<int>(valAsFloat) << std::endl;
    }
    else
    {
        std::cout << "char: impossible\nint: impossible" << std::endl;
    }
    std::cout << std::fixed << std::setprecision(1) << "float: " << valAsFloat << "f\ndouble: "
              << static_cast<double>(valAsFloat) << std::endl;
}

void printFromDouble(double valAsDouble)
{
    if (!isNumInFloatRange(valAsDouble) && !std::isinf(valAsDouble))
    {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: " << valAsDouble << std::endl;
    }
    else
    {
        if (isNumInIntRange(valAsDouble))
        {
            if (isNumInCharRange(valAsDouble))
            {
                if (std::isprint(static_cast<int>(valAsDouble)))
                {
                    std::cout << "char: " << static_cast<char>(valAsDouble) << std::endl;
                }
                else
                {
                    std::cout << "char: Non displayable" << std::endl;
                }
            }
            else
            {
                std::cout << "char: impossible" << std::endl;
            }
            std::cout << "int: " << static_cast<int>(valAsDouble) << std::endl;
        }
        else
        {
            std::cout << "char: impossible\nint: impossible" << std::endl;
        }
        std::cout << "float: " << static_cast<float>(valAsDouble) << "f\ndouble: " << valAsDouble << std::endl;
    }
}