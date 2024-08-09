#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>

BitcoinExchange::BitcoinExchange()
{
	std::ifstream dataFile("data.csv");
	if (!dataFile)
	{
		throw std::runtime_error("Error: unable to open the data file");
	}
	std::string line;
	std::getline(dataFile, line);
	while (std::getline(dataFile, line))
	{
		const std::size_t commaPosition = line.find(',');
		if (commaPosition != std::string::npos)
		{
			this->exchangeData[line.substr(0, commaPosition)]
				= strtod(line.substr(commaPosition + 1).c_str(), NULL);
		}
	}
	std::cout << "printing data" << std::endl;
	
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& toCopy) : exchangeData(toCopy.exchangeData) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& toCopy)
{
    if (this != &toCopy)
    {
        this->exchangeData = toCopy.exchangeData;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{

}

void BitcoinExchange::printExchangedValues(const char* fileName)
{
	std::ifstream inputFile(fileName);
	if (!inputFile)
    {
	    throw std::runtime_error("Error: unable to open the input file");
    }
	std::string inputLine;
	std::getline(inputFile, inputLine);
	while (std::getline(inputFile, inputLine))
    {
		std::string inputDate;
		float inputValue;
		this->assignDateAndValue(inputLine, inputDate, inputValue);
    }
}

void BitcoinExchange::assignDateAndValue(std::string& inputLine, std::string& inputDate, float& inputValue)
{
	const std::size_t pipePosition = inputLine.find('|');
	if (pipePosition == std::string::npos)
	{
		throw std::invalid_argument("Error: '|' separator missing");
	}
	inputDate = inputLine.substr(0, pipePosition);
	for (size_t i = 0; i < inputDate.size(); ++i)
	{
		if (((i == 4 || i == 7) && inputDate[i] != '-') || (i != 4 && i != 7 && !isdigit(inputDate[i]))
		    || std::atoi(inputDate.substr(0, 4).c_str()) > 2024
		    || std::atoi(inputDate.substr(5, 7).c_str()))
		{
			throw std::invalid_argument("Error: wrong date format");
		}
	}
	char* end;
	inputValue = strtof(inputLine.substr(pipePosition + 1).c_str(), &end);
	if (*end != 0 || inputValue < 0 || inputValue > 1000)
	{
		throw std::invalid_argument("Error: value not valid");
	}
}

bool BitcoinExchange::isDateValid(std::string &inputDate)
{
	char *end;
	long year = std::strtol(inputDate.substr(0, 4).c_str(), &end, 10);
	if (*end != 0 || year < 0 || year > 2024)
	{
		return false;
	}
	long month = std::strtol(inputDate.substr(5, 7).c_str(), &end, 10);
	if (*end != 0 || ())
	return true;
}

bool BitcoinExchange::isLeapYear(long year)
{
	if (year % 4 != 0)
	{
		return false;
	}
	if (year % 100 != 0)
	{
		return true;
	}
	if (year % 400 == 0)
	{
		return true;
	}
	return false;
}