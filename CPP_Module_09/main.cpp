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
    BitcoinExchange btcExchange;
    return 0;
}
