#include <iostream>
#include <csignal>
#include <fstream>
#include <map>
#include <unistd.h>
#include <sys/unistd.h>
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
	std::map<std::string, double> dateValueBtc;
	std::string line;
	std::getline(input_file, line);
	while (std::getline(input_file, line))
	{
		const std::size_t commaPosition = line.find(',');
		if (commaPosition != std::string::npos)
		{
			dateValueBtc[line.substr(0, commaPosition)] = strtod(line.substr(commaPosition + 1).c_str(), NULL);
		}
	}
	for (std::map<std::string, double>::iterator i = dateValueBtc.begin(); i != dateValueBtc.end(); i++)
	{
		std::cout << i->first + " => " << i->second << std::endl;
	}
	return 0;
}
