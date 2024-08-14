#ifndef PMERGME_HPP
#define PMERGME_HPP
#include <cstddef>

#define VECTOR
#define DEQUE
#define OTHER



// template class to allow using alghoritm with both std::vector and std::deque
template <typename ContainerBasic, typename ContainerPair>
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
	ContainerBasic nums;
	ContainerPair numsPairs;
};

#include "PmergeMe.tpp"

#endif