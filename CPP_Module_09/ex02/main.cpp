#include "Colors.hpp"
#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << RED "Error: incorrect number of arguments\n" LIGHT_CYAN "Usage: ./PmergeMe <arg> <arg2> ..." RESET
			<< std::endl;
		return 2;
	}
	try
	{
		std::cout << LIGHT_CYAN "\nvector:" RESET << std::endl;
		PmergeMe<std::vector<int>, std::vector<std::pair<int, int> > > vecSort(argc, argv);
		vecSort.sortFordJohnson();
		std::cout << LIGHT_CYAN "\ndeque:" RESET << std::endl;
		PmergeMe<std::deque<int>, std::deque<std::pair<int, int> > > deqSort(argc, argv);
		deqSort.sortFordJohnson();
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << RED << e.what() << std::endl;
	}
	return 0;
}