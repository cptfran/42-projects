#ifndef PMERGME_HPP
#define PMERGME_HPP
#include <cstddef>

// Template class to allow using alghoritm with both std::vector and std::deque.
template <typename ContainerBasic, typename ContainerPair>
class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(int argc, char **argv);
	PmergeMe(const PmergeMe& toCopy);
	PmergeMe& operator=(const PmergeMe& toCopy);
	~PmergeMe();
	void printNums();
	void printSortedNums();
	void sortFordJohnson();
	void moveLargerInPairFirst();
	void splitAndInsertionSort();
	void recursiveInsertionSort(ContainerPair& list, int listSize);
	void createMainAndLowerChain();
	void initJacobsthalSequence(size_t n);
	void insertLowerChainNumsToMainChain();
	bool sortedChecker();
private:
	ContainerBasic nums, mainChain, lowerChain, jacobsthalSeq;
	ContainerPair numsPairs, firstHalf, secondHalf;
};

#include "PmergeMe.tpp"

#endif