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
    std::ifstream dataFile("data.csv");
    if (!dataFile)
    {
        std::cerr << RED "Error: unable to open the data file: 'data.csv'" RESET << std::endl;
        return 3;
    }
    std::ifstream inputFile(argv[1]);
    if (!inputFile)
    {
        std::cerr << RED "Error: unable to open the input file: '" << argv[1] << "'" RESET << std::endl;
        return 4;
    }
    std::map<std::string, double> dateValueBtcData = init_data_as_map_container_from_file(dataFile);
    std::map<std::string, double> dateValueBtcInput = init_data_as_map_container_from_file(inputFile);
    return 0;
}

std::map<std::string, double> init_data_as_map_container_from_file(std::ifstream& file)
{
    std::map<std::string, double> dateExchangeRateBtc;
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        const std::size_t commaPosition = line.find(',');
        if (commaPosition != std::string::npos)                                                                                          
        {
            dateExchangeRateBtc[line.substr(0, commaPosition)] = strtod(line.substr(commaPosition + 1).c_str(), NULL);
        }
    }
    return dateExchangeRateBtc;
}