#include <cstdlib>
#include <stdexcept>
#include <cerrno>
#include <climits>
#include <vector>
#include "PmergeMe.hpp"

template <typename Container>
PmergeMe<Container>::PmergeMe()
{

}

template <typename Container>
PmergeMe<Container>::PmergeMe(int argc, char **argv)
{
	std::vector<int> tmp;
	for (size_t i = 1; i < argc; ++i)
	{
		errno = 0;
		char *endPtr;
		long num = std::strtol(argv[i], &endPtr, 10);
		if (endPtr == argv[i] || *endPtr != '\0' || errno == ERANGE || num < INT_MIN || num > INT_MAX)
		{
			throw std::invalid_argument("Error: invalid input");
		}
		if (num < 0)
		{
			throw std::invalid_argument("Error: not a positive integer");
		}
		tmp.push_back(static_cast<int>(num));
	}
	for (size_t i = 0; i + 1 < tmp.size(); i += 2)
	{
		numsPairs.emplace_back(tmp[i], tmp[i + 1]);
	}
}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe<Container>& toCopy) : numsPairs(toCopy.numsPairs)
{

}

template <typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(const PmergeMe<Container>& toCopy)
{
	if (this != &toCopy)
	{
		this->numsPairs = toCopy.numsPairs;
	}
	return *this;
}

template <typename Container>
PmergeMe<Container>::~PmergeMe()
{

}

template <typename Container>
void PmergeMe<Container>::mergeInsertionSort()
{
// init pairs, if odd number of elements, for now leave the last element

// "For each pair, determine which element is larger and which is smaller."

// "Recursively sort the larger elements from each pair. This forms the initial "main chain" or sequence."

// "This step involves inserting the smaller elements (from the initial pairs) into the sequence formed by the
// larger elements. The insertion is done to maintain the sorted order. The method of insertion is where the
// algorithm gets more complex and involves using previously determined positions to minimize comparisons."

//	"The Jacobsthal sequence (or a similar method) can be used to optimize the order of insertion for the smaller
//	elements. However, this is not a universally described step in all explanations of the Ford-Johnson algorithm. The
//	key idea is to minimize the number of comparisons needed to insert the remaining elements into the sorted sequence."

//	"The remaining elements (the smaller ones from the initial pairs) are inserted into the sorted sequence of larger
//	elements. The insertion should maintain the sorted order, and the goal is to do this with the minimum number of
//	comparisons."
}
