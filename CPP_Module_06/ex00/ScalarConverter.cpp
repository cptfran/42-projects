#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cstdio>
#include <cstring>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

bool isPureDigitStr(const char* str) {
    for (int i = 0; i < std::strlen(str); i++) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

int verifyType(const char* val) {
    size_t valLen = std::strlen(val);
    if (valLen == 1 && !std::isdigit(val[0]) && std::isprint(val[0])) {
        return 1;
    } else if (valLen <= 10 && isPureDigitStr(val)) {
        return 2;
    }
}
//void convert(const char* val) {
//    'check which type'
//    case 'char string':
//        'convert to char'
//        'print char, convert to int, convert to float, convert to double'
//    case 'int string'
//        'convert to int'
//        'print convert to char, int, convert to float, convert to double'
//    case 'float string'
//        'convert to float'
//        'print convert to char, convert to int, float, convert to double'
//    case 'double string'
//        'convert to double'
//        'print convert to char, convert to int, convert to float, double'
//}

void ScalarConverter::convert(const char* val) {
    // 1 - type is char, 2 - type is int, 3 - type is float, 4 - type is double
    int type = verifyType(val);
}