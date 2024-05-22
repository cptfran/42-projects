#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& toCopy);
    ScalarConverter& operator=(const ScalarConverter& toCopy);
    ~ScalarConverter();
    static void convert(const char* val);
};

bool isPureDigitStr(const char* str);
int verifyType(const char* val);

#endif