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
	void assignDateAndValue(std::string& inputLine, std::string& inputDate, float& inputValue);
	bool isDateValid(std::string& inputDate);
	bool isLeapYear(long year);
private:
    std::map<std::string, float> exchangeData;
};

#endif