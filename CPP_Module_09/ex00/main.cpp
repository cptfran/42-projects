#include <iostream>
#include <csignal>
#include <fstream>
#include <map>
#include <cstdlib>
#include "Colors.hpp"
#include "BitcoinExchange.hpp"

int main(const int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << RED "Error: incorrect number of arguments\n" LIGHT_CYAN "Usage: ./btc <filename>" RESET << std::endl;
        return 2;
    }
    BitcoinExchange btcExchange;
	try
	{
		btcExchange.printExchangedValues(argv[1]);
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
    return 0;
}
