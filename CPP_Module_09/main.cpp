#include <iostream>
#include <csignal>
#include <fstream>
#include <map>
#include <cstdlib>
#include "Colors.hpp"
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << RED "Error: incorrect number of arguments\n" LIGHT_CYAN "Usage: ./btc <filename>" RESET << std::endl;
        return 2;
    }
    std::ifstream data_file("data.csv");
    if (!data_file)
    {
        std::cerr << RED "Error: unable to open the data file: 'data.csv'" RESET << std::endl;
        return 3;
    }
    std::ifstream input_file(argv[1]);
    if (!input_file)
    {
        std::cerr << RED "Error: unable to open the input file: '" << argv[1] << "'" RESET << std::endl;
        return 4;
    }
    // init map container for data file
    std::map<std::string, double> dateExchangeRateBtcData;
    std::string lineData;
    std::getline(data_file, lineData);
    while (std::getline(input_file, lineData))
    {
        const std::size_t commaPosition = lineData.find(',');
        if (commaPosition != std::string::npos)                                                                                          
        {
            dateExchangeRateBtcData[lineData.substr(0, commaPosition)] = strtod(lineData.substr(commaPosition + 1).c_str(), NULL);
        }
    }
    for (std::map<std::string, double>::iterator i = dateExchangeRateBtcData.begin(); i != dateExchangeRateBtcData.end(); ++i)
    {
        std::cout << i->first + " => " << i->second << std::endl;
    }
    // init map container for input file
    std::map<std::string, double> dateValueBtcInput;
    std::string lineInput;
    std::getline(input_file, lineInput);
    while (std::getline(input_file, lineInput))
    {
        const std::size_t commaPosition = lineInput.find('|');
        if (commaPosition != std::string::npos)
        {
            dateValueBtcInput[lineInput.substr(0, commaPosition)] = strtod(lineInput.substr(commaPosition + 1).c_str(), NULL);
        }
    }
    for (std::map<std::string, double>::iterator i = dateValueBtcInput.begin(); i != dateValueBtcInput.end(); ++i)
    {
        std::cout << i->first + " => " << i->second << std::endl;
    }
    return 0;
}