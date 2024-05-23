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

//StringRecognition.cpp
bool isPrintableStr(const std::string& str, size_t strLen);
bool isCharStr(const std::string& str, size_t strLen);
bool isIntStr(const std::string& str);
bool isFloatString(const std::string& str, size_t strLen);
bool isDoubleString(const std::string& str);
int verifyType(const std::string& val);

//NumRange.cppw
bool isNumInCharRange(double num);
bool isNumInIntRange(double num);
bool isNumInFloatRange(double num);

//Print.cpp
void printFromChar(char valAsChar);
void printFromInt(int valAsInt);
void printFromFloat(float valAsFloat);
void printFromDouble(double valAsDouble);

#endif