#include "ScalarConverter.hpp"
#include <limits>

bool isNumInCharRange(double num) {
    return num >= std::numeric_limits<char>::min() && num <= std::numeric_limits<char>::max();
}

bool isNumInIntRange(double num) {
    return num >= std::numeric_limits<int>::min() && num <= std::numeric_limits<int>::max();
}

bool isNumInFloatRange(double num) {
    return num >= std::numeric_limits<float>::min() && num <= std::numeric_limits<float>::max();
}