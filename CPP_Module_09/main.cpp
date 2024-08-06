#include <iostream>
#include <csignal>
#include <fstream>
#include <map>
#include <unistd.h>
#include <sys/unistd.h>
#include "Colors.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED "Error: incorrect number of arguments\n" LIGHT_CYAN "Usage: ./btc <filename>" RESET << std::endl;
		return 2;
	}
	if (access(argv[1], F_OK) == -1)
	{
		std::cerr << RED "Error: no such file or directory" RESET << std::endl;
		return 3;
	}
	if (access(argv[1], R_OK) == -1)
	{
		std::cerr << RED "Error: permission denied" RESET << std::endl;
		return 4;
	}
	std::ifstream file(argv[1]);
	if (!file)
	{
		std::cerr << RED << "Error: unable to open the file: '" << argv[1] << "'" RESET << std::endl;
		return 5;
	}
	std::map<std::string, double> dateValueBtc;
	std::string line;
	while (std::getline(file, line))
	{
		const std::size_t commaPosition = line.find(',');
		if (commaPosition != std::string::npos)
		{
			dateValueBtc[line.substr(0, commaPosition)] = strtod(line.substr(commaPosition + 1).c_str(), NULL);
		}
	}
	for (std::map<std::string, double>::iterator i = dateValueBtc.begin(); i != dateValueBtc.end(); ++i)
	{
		std::cout << i->first + " => " << i->second << std::endl;
	}
	return 0;
}