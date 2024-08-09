#include "BitcoinExchange.hpp"
#include <iostream>
#include <csignal>
#include <fstream>
#include <map>
#include <cstdlib>
#include "Colors.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& toCopy) : exchangeData(toCopy.exchangeData) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& toCopy)
{
    if (this != &toCopy)
    {
        this->exchangeData = toCopy.exchangeData;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

int BitcoinExchange::setExchangeData(const std::string& fileName)
{
    const std::ifstream dataFile(fileName);
    if (!dataFile)
    {
        std::cerr << RED "Error: unable to open the data data file: '" << fileName << "'" RESET << std::endl;
        return 1;
    }
    std::string line;
    std::getline(dataFile, line);
    while (std::getline(dataFile, line))
    {
        const std::size_t commaPosition = line.find(',');
        if (commaPosition != std::string::npos)
        {
            this->exchangeData[line.substr(0, commaPosition)] = strtod(line.substr(commaPosition + 1).c_str(), NULL);
        }
    }
    return 0;
}

int BitcoinExchange::printExchangedValues(const std::string& fileName)
{
    const std::ifstream inputFile(fileName);
    if (!inputFile)
    {
        std::cerr << RED "Error: unable to open the input file: '" << fileName << "'" RESET << std::endl;
        return 1;
    }
    std::string line;
    std::getline(inputFile, line);
    std::map<std::string, double> inputData;
    while (std::getline(inputFile, line))
    {
        const std::size_t pipePosition = line.find('|');
        if (pipePosition != std::string::npos)
        {
            inputData[line.substr(0, pipePosition)] = strtod(line.substr(pipePosition + 1).c_str(), NULL);
        }
    }
    for (std::map<std::string, double>::iterator i = inputData.begin(); i != inputData.end(); ++i)
    {
        std::cout << i->first << "=>" << i->second << std::endl;
    }
    return 0;
}
