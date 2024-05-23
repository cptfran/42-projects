#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
public:
    static void convert(const std::string& val);
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& toCopy);
    ScalarConverter& operator=(const ScalarConverter& toCopy);
    ~ScalarConverter();
};

bool isPureDigitStr(const std::string& str);
int verifyType(const std::string& val);

#endif