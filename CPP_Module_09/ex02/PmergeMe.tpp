#include <cstdlib>
#include <stdexcept>
#include <cerrno>
#include <climits>
#include <vector>
#include <iostream>
#include <limits>

template <typename ContainerBasic, typename ContainerPair>
PmergeMe<ContainerBasic, ContainerPair>::PmergeMe()
{

}

template <typename ContainerBasic, typename ContainerPair>
PmergeMe<ContainerBasic, ContainerPair>::PmergeMe(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
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
		this->nums.push_back(static_cast<int>(num));
	}
	for (size_t i = 0; i + 1 < this->nums.size(); i += 2)
	{
		this->numsPairs.push_back(std::make_pair(this->nums[i], this->nums[i + 1]));
	}
}

template <typename ContainerBasic, typename ContainerPair>
PmergeMe<ContainerBasic, ContainerPair>::PmergeMe(const PmergeMe<ContainerBasic, ContainerPair>& toCopy)
	: nums(toCopy.nums), numsPairs(toCopy.numsPairs)
{

}

template <typename ContainerBasic, typename ContainerPair>
PmergeMe<ContainerBasic, ContainerPair>& PmergeMe<ContainerBasic, ContainerPair>::operator=(const PmergeMe<ContainerBasic, ContainerPair>& toCopy)
{
	if (this != &toCopy)
	{
		this->nums = toCopy.nums;
		this->numsPairs = toCopy.numsPairs;
	}
	return *this;
}

template <typename ContainerBasic, typename ContainerPair>
PmergeMe<ContainerBasic, ContainerPair>::~PmergeMe()
{

}

template <typename ContainerBasic, typename ContainerPair>
void PmergeMe<ContainerBasic, ContainerPair>::printNums()
{
	std::cout << LIGHT_RED "\nBefore:" RESET << std::endl;
	for (size_t i = 0; i < this->nums.size(); ++i)
	{
		std::cout << this->nums[i] << " ";
	}
}

template <typename ContainerBasic, typename ContainerPair>
void PmergeMe<ContainerBasic, ContainerPair>::printSortedNums()
{
	std::cout << LIGHT_GREEN "\n\nAfter:" RESET << std::endl;
	for (size_t i = 0; i < this->mainChain.size(); ++i)
	{
		std::cout << this->mainChain[i] << " ";
	}
}

template <typename ContainerBasic, typename ContainerPair>
void PmergeMe<ContainerBasic, ContainerPair>::sortFordJohnson()
{
// For each pair, determine which element is larger and which is smaller.
	this->moveLargerInPairFirst();

// Divide the list into two halves. Recursively sort the larger elements from each pair
	this->splitAndInsertionSort();

// Sort bigger numbers from each pair and put them into the main chain, create lowerChain from lower numbers.
// Indexes are relative to bigger number indexes
	this->createMainAndLowerChain();
	
//	Init Jacobsthal sequence that will help to insert remaining elements into the main chain
	this->initJacobsthalSequence(this->lowerChain.size() + 1);

//	Insert lowerChain nums into mainChain using binarySearch connected with Jacobsthal sequence.
//  Jacobsthal sequence helps to narrow down the area in which to use the binary search.
	this->insertLowerChainNumsToMainChain();
	
//	Check if nums are sorted
	this->sortedChecker();
}

template <typename ContainerBasic, typename ContainerPair>
void PmergeMe<ContainerBasic, ContainerPair>::moveLargerInPairFirst()
{
	for (size_t i = 0; i < this->numsPairs.size(); ++i)
	{
		if (this->numsPairs[i].first < this->numsPairs[i].second)
		{
			std::swap(this->numsPairs[i].first, this->numsPairs[i].second);
		}
	}
}

template <typename ContainerBasic, typename ContainerPair>
void PmergeMe<ContainerBasic,ContainerPair>::splitAndInsertionSort()
{
	size_t midIdxNumsPairs = this->numsPairs.size() / 2;
	for (size_t i = 0; i < this->numsPairs.size(); ++i)
	{
		if (i < midIdxNumsPairs)
		{
			this->firstHalf.push_back(this->numsPairs[i]);
		}
		else
		{
			this->secondHalf.push_back(this->numsPairs[i]);
		}
	}
	this->recursiveInsertionSort(this->firstHalf, this->firstHalf.size());
	this->recursiveInsertionSort(this->secondHalf, this->secondHalf.size());
}

template <typename ContainerBasic, typename ContainerPair>
void PmergeMe<ContainerBasic, ContainerPair>::recursiveInsertionSort(ContainerPair& list, int listSize)
{
	if (listSize <= 1)
		return;
	this->recursiveInsertionSort(list, listSize - 1);
	typename ContainerPair::value_type last = list[listSize - 1];
	int j = listSize - 2;
	for (; j >= 0 && list[j].first >= last.first; --j)
	{
		list[j + 1] = list[j];
	}
	list[j + 1] = last;
}

template <typename ContainerBasic, typename ContainerPair>
void PmergeMe<ContainerBasic, ContainerPair>::createMainAndLowerChain()
{
	size_t i = 0, j = 0;
	while (i < this->firstHalf.size() && j < this->secondHalf.size())
	{
		if (this->firstHalf[i].first < this->secondHalf[j].first)
		{
			this->mainChain.push_back(this->firstHalf[i].first);
			this->lowerChain.push_back(this->firstHalf[i].second);
			++i;
		}
		else
		{
			this->mainChain.push_back(this->secondHalf[j].first);
			this->lowerChain.push_back(this->secondHalf[j].second);
			++j;
		}
	}
	while (i < this->firstHalf.size())
	{
		this->mainChain.push_back(this->firstHalf[i].first);
		this->lowerChain.push_back(this->firstHalf[i].second);
		++i;
	}
	while (j < this->secondHalf.size())
	{
		this->mainChain.push_back(this->secondHalf[j].first);
		this->lowerChain.push_back(this->secondHalf[j].second);
		++j;
	}
}

template <typename ContainerBasic, typename ContainerPair>
void PmergeMe<ContainerBasic, ContainerPair>::initJacobsthalSequence(size_t n)
{
	this->jacobsthalSeq.push_back(1);
	if (n <= 1)
	{
		return;
	}
	this->jacobsthalSeq.push_back(1);
	for (size_t i = 2; i < n; ++i)
	{
		this->jacobsthalSeq.push_back(this->jacobsthalSeq[i - 2] * 2 + this->jacobsthalSeq[i - 1]);
	}
}

template <typename ContainerBasic, typename ContainerPair>
void PmergeMe<ContainerBasic, ContainerPair>::insertLowerChainNumsToMainChain()
{
	typename ContainerBasic::iterator insertPos;
	for (size_t i = 0; i < this->lowerChain.size(); ++i)
	{
		size_t maxSearchIndex = std::min(static_cast<size_t>(jacobsthalSeq[i] * 2), this->mainChain.size());
		insertPos = std::lower_bound(this->mainChain.begin(),
		                             this->mainChain.begin() + maxSearchIndex,
		                             this->lowerChain[i]);
		this->mainChain.insert(insertPos, this->lowerChain[i]);
	}
	if (this->nums.size() % 2 != 0)
	{
		int solitary = *(this->nums.end() - 1);
		insertPos = std::lower_bound(this->mainChain.begin(), this->mainChain.end(), solitary);
		this->mainChain.insert(insertPos, solitary);
	}
}

template <typename ContainerBasic, typename ContainerPair>
bool PmergeMe<ContainerBasic, ContainerPair>::sortedChecker()
{
	for (size_t i = 1; i < mainChain.size(); ++i)
	{
		if (this->mainChain[i] < this->mainChain[i - 1])
		{
			return false;
		}
	}
	return true;
}