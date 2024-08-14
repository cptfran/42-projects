#ifndef PMERGME_HPP
#define PMERGME_HPP
#include <cstddef>

// vector
// deque

template <typename Container>
class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(int argc, char **argv);
	PmergeMe(const PmergeMe& toCopy);
	PmergeMe& operator=(const PmergeMe& toCopy);
	~PmergeMe();
	void mergeInsertionSort();
private:
	Container numsPairs;
};

#endif