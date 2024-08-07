#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits>
#include <cerrno>

bool isPrintableStr(const std::string& str, size_t strLen)
{
    for (size_t i = 0; i < strLen; i++)
    {
        if (!std::isprint(str[i]))
        {
            return false;
        }
    }
    return true;
}

bool isCharStr(const std::string& str, size_t strLen)
{
    if (strLen == 1 && !std::isdigit(str[0]))
    {
        return true;
    }
    return false;
}

bool isIntStr(const std::string& str)
{
    char* end;
    errno = 0; // reset errno before the call (it's global var so can store old errno)
//    Convert the string to a long long int using strtoll to check if its int
    long long int rangeChecker = std::strtoll(str.c_str(), &end, 10);
//    Check if the conversion resulted in an out of range error
//    errno is a global variable that is set by some functions (like strtoll) to indicate what error occurred
    if (errno == ERANGE || *end != 0 || end == str.c_str())
    {
//        if errno == ERANGE the value to convert was out of range for a long long int
//        if *end != 0 not entire string was converted, if entire string is converted it should be 0
//        if end == str.c_str() the conversion didn't start because end is pointing to the start of the string
        return false;
    }
//    check if the converted value is withing the range of an int
    if (rangeChecker < std::numeric_limits<int>::min() || rangeChecker > std::numeric_limits<int>::max())
    {
        return false;
    }
    return true;
}

bool isFloatString(const std::string& str, size_t strLen)
{
    if (str[strLen - 1] != 'f' && str[strLen - 1] != 'F')
    {
        return false;
    }
    char* end;
    errno = 0;
    std::string strWithoutF = str.substr(0, strLen - 1);
    float rangeChecker = std::strtof(strWithoutF.c_str(), &end);
    (void)rangeChecker;
    if (errno == ERANGE || *end != 0 || end == strWithoutF.c_str())
    {
        return false;
    }
    return true;
}

bool isDoubleString(const std::string& str)
{
    char *end;
    errno = 0;
    double rangeChecker = std::strtod(str.c_str(), &end);
    (void)rangeChecker;
    if (errno == ERANGE || *end != 0 || end == str.c_str())
    {
        return false;
    }
    return true;
}

int verifyType(const std::string& val)
{
    const size_t valLen = val.length();
    if (!isPrintableStr(val, valLen))
    {
        return -1;
    }
    if (isCharStr(val, valLen))
    {
        return 1;
    }
    if (isIntStr(val))
    {
        return 2;
    }
    if (isFloatString(val, valLen))
    {
        return 3;
    }
    if (isDoubleString(val))
    {
        return 4;
    }
    return -2;
}