#include "ScalarConverter.hpp"
#include "Colors.hpp"
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <limits>
#include <cerrno>
#include <iomanip>

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

bool isPrintableStr(const std::string& str, size_t strLen) {
    for (size_t i = 0; i < strLen; i++) {
        if (!std::isprint(str[i])) {
            return false;
        }
    }
    return true;
}

bool isCharStr(const std::string& str, size_t strLen) {
    if (strLen == 1 && !std::isdigit(str[0])) {
        return true;
    }
    return false;
}

bool isIntStr(const std::string& str) {
    char* end;
    errno = 0; // reset errno before the call (it's global var so can store old errno)
//    Convert the string to a long long int using strtoll to check if its int
    long long int rangeChecker = std::strtoll(str.c_str(), &end, 10);
//    Check if the conversion resulted in an out of range error
//    errno is a global variable that is set by some functions (like strtoll) to indicate what error occurred
    if (errno == ERANGE || *end != 0 || end == str.c_str()) {
//        if errno == ERANGE the value to convert was out of range for a long long int
//        if *end != 0 not entire string was converted, if entire string is converted it should be 0
//        if end == str.c_str() the conversion didn't start because end is pointing to the start of the string
        return false;
    }
//    check if the converted value is withing the range of an int
    if (rangeChecker < std::numeric_limits<int>::min() || rangeChecker > std::numeric_limits<int>::max()) {
        return false;
    }
    return true;
}

bool isFloatString(const std::string& str, size_t strLen) {
    if (str[strLen - 1] != 'f' && str[strLen - 1] != 'F') {
        return false;
    }
    char* end;
    errno = 0;
    std::string strWithoutF = str.substr(0, strLen - 1);
    float rangeChecker = std::strtof(strWithoutF.c_str(), &end);
    (void)rangeChecker;
    if (errno == ERANGE || *end != 0 || end == strWithoutF.c_str()) {
        return false;
    }
    return true;
}

bool isDoubleString(const std::string& str) {
    char *end;
    errno = 0;
    double rangeChecker = std::strtod(str.c_str(), &end);
    (void)rangeChecker;
    if (errno == ERANGE || *end != 0 || end == str.c_str()) {
        return false;
    }
    return true;
}

int verifyType(const std::string& val) {
    const size_t valLen = val.length();
    if (!isPrintableStr(val, valLen)) {
        return -1;
    }
    if (isCharStr(val, valLen)) {
        return 1;
    }
    if (isIntStr(val)) {
        return 2;
    }
    if (isFloatString(val, valLen)) {
        return 3;
    }
    if (isDoubleString(val)) {
        return 4;
    }
    return -2;
}

bool isNumInCharRange(long long int num) {
    return num >= std::numeric_limits<char>::min() && num <= std::numeric_limits<char>::max();
}

void printFromChar(char valAsChar) {
    std::cout << "char: " << valAsChar << "\nint: " << static_cast<int>(valAsChar) << std::fixed
              << std::setprecision(1) << "\nfloat: " << static_cast<float>(valAsChar) << "f\ndouble: "
              << static_cast<double>(valAsChar) << std::endl;
}

void printFromInt(int valAsInt) {
    if (isNumInCharRange(valAsInt)) {
        std::cout << "char: " << static_cast<char>(valAsInt) << "\nint: " << valAsInt << std::fixed
                  << std::setprecision(1) << "\nfloat: " << static_cast<float>(valAsInt) << "f\ndouble: "
                  << static_cast<double>(valAsInt) << std::endl;
    } else {
        std::cout << "char: impossible\nint: " << valAsInt << std::fixed << std::setprecision(1) << "\nfloat: "
                  << static_cast<float>(valAsInt) << "f\ndouble: " << static_cast<double>(valAsInt) << std::endl;
    }
}

void ScalarConverter::convert(const std::string& val) {
//      1 - type is char, 2 - type is int, 3 - type is float, 4 - type is double, -1 - not printable char,
//     -2 - out of range or not handled char
    int type = verifyType(val);
    switch (type) {
        case 1:
            printFromChar(val[0]);
            break;
        case 2:
            printFromInt(std::atoi(val.c_str()));
            break;
        case 3:
            std::cout << "float" << std::endl;
            break;
        case 4:
            std::cout << "double" << std::endl;
            break;
        case -1:
            std::cerr << RED "Error: found not printable char" RESET << std::endl;
            break;
        case -2:
            std::cerr << RED "Error: value is out of range or format is wrong" RESET << std::endl;
            break;
        default:
            std::cerr << RED "Error: idk what happened" RESET << std::endl;
    }
}