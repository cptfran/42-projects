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
    int setExchangeData(const std::string& fileName);
    int printExchangedValues(const std::string& fileName);
private:
    std::map<std::string, double> exchangeData;
};

#endif