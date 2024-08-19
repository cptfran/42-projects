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
		// Vector sorting.
		PmergeMe<std::vector<int>, std::vector<std::pair<int, int> > > vecSort(argc, argv);
		vecSort.printNums();
		clock_t start = clock();
		vecSort.sortFordJohnson();
		clock_t end = clock();
		vecSort.printSortedNums();
		if (vecSort.sortedChecker())
		{
			std::cout << LIGHT_GREEN "\n\n:) :) :) SORTED :) :) :)" RESET << std::endl;
		}
		else
		{
			std::cerr << RED "!!! NOT SORTED !!!" RESET << std::endl;
			return 3;
		}
		double elapsedTimeSec = static_cast<double>(end - start) / CLOCKS_PER_SEC;
		double elapsedTimeMicrosec = elapsedTimeSec * 1000000.0;
		std::cout << "Time to process a range of " LIGHT_CYAN << argc - 1
		          << " elements" RESET " with " BLUE "std::vector" RESET ": " << LIGHT_GREEN << elapsedTimeMicrosec
				  << " microseconds; " PURPLE << elapsedTimeSec << " seconds." RESET << std::endl;
		
		// Deque sorting.
		PmergeMe<std::deque<int>, std::deque<std::pair<int, int> > > deqSort(argc, argv);
		start = clock();
		deqSort.sortFordJohnson();
		end = clock();
		if (deqSort.sortedChecker())
		{
			std::cout << LIGHT_GREEN "\n:) :) :) SORTED :) :) :)" RESET << std::endl;
		}
		else
		{
			std::cerr << RED "!!! NOT SORTED !!!" RESET << std::endl;
			return 4;
		}
		elapsedTimeSec = static_cast<double>(end - start) / CLOCKS_PER_SEC;
		elapsedTimeMicrosec = elapsedTimeSec * 1000000.0;
		std::cout << "Time to process a range of " LIGHT_CYAN << argc - 1
		          << " elements" RESET " with " YELLOW "std::deque" RESET ": "
				  << LIGHT_GREEN << elapsedTimeMicrosec << " microseconds; " PURPLE << elapsedTimeSec
				  << " seconds." RESET << std::endl;
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << RED << e.what() << std::endl;
	}
	return 0;
}