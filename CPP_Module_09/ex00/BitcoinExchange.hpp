#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <fstream>
#include <map>

class BitcoinExchange
{
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& toCopy);
    BitcoinExchange& operator=(const BitcoinExchange& toCopy);
    ~BitcoinExchange();
    void printExchangedValues(const char* fileName);
	static void assignDateAndValue(std::string& inputLine, std::string& inputDate, float& inputValue);
	static bool isDateValid(const std::string& inputDate);
	static bool isLeapYear(long year);
private:
    std::map<std::string, float> exchangeData;
};

#endif