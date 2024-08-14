#include <iostream>
#include <vector>
#include <deque>
#include "Colors.hpp"
#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << RED "Error: incorrect number of arguments\n" LIGHT_CYAN "Usage: ./PmergeMe <arg> <arg2> ..." RESET
			<< std::endl;
		return 2;
	}
	PmergeMe<std::vector<int> > vecSort(argc, argv);
	
	PmergeMe<std::deque<int> > deqSort(argc, argv);
}