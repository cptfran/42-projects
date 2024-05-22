#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
public:
    static void convert(const char* val);
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& toCopy);
    ScalarConverter& operator=(const ScalarConverter& toCopy);
    ~ScalarConverter();
};

bool isPureDigitStr(const char* str);
int verifyType(const char* val);

#endif