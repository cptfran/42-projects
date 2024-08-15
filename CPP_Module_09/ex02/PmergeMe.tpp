#include <cstdlib>
#include <stdexcept>
#include <cerrno>
#include <climits>
#include <vector>
#include <iostream>

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
		nums.push_back(static_cast<int>(num));
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
void PmergeMe<ContainerBasic, ContainerPair>::sortFordJohnson()
{
// "For each pair, determine which element is larger and which is smaller."
	this->moveLargerInPairTop();

// "Divide the list into two halves"
// "Recursively sort the larger elements from each pair. This forms the initial 'main chain' or sequence."
	this->splitAndInsertionSort();

// "This step involves inserting the smaller elements (from the initial pairs) into the sequence formed by the
// larger elements. The insertion is done to maintain the sorted order. The method of insertion is where the
// algorithm gets more complex and involves using previously determined positions to minimize comparisons."
	this->createMainAndLowerChain();
	
//	"The Jacobsthal sequence (or a similar method) can be used to optimize the order of insertion for the smaller
//	elements. However, this is not a universally described step in all explanations of the Ford-Johnson algorithm. The
//	key idea is to minimize the number of comparisons needed to insert the remaining elements into the sorted sequence."

//	"The remaining elements (the smaller ones from the initial pairs) are inserted into the sorted sequence of larger
//	elements. The insertion should maintain the sorted order, and the goal is to do this with the minimum number of
//	comparisons."
}

template <typename ContainerBasic, typename ContainerPair>
void PmergeMe<ContainerBasic, ContainerPair>::moveLargerInPairTop()
{
	std::cout << GRAY "\nSTEP 1 && STEP 2: group the elements of x into [n/2] pairs of elements determine the "
	             "larger of the two elements in each pair" RESET << std::endl;
	for (size_t i = 0; i < this->numsPairs.size(); ++i)
	{
		if (this->numsPairs[i].first < this->numsPairs[i].second)
		{
			std::swap(this->numsPairs[i].first, this->numsPairs[i].second);
		}
		std::cout << this->numsPairs[i].first << " " << this->numsPairs[i].second << std::endl;
	}
}

template <typename ContainerBasic, typename ContainerPair>
void PmergeMe<ContainerBasic,ContainerPair>::splitAndInsertionSort()
{
	std::cout << GRAY "\nSTEP 3: Divide list into 2 halves. Recursively sort the larger elements from each pair" RESET
		<< std::endl;
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
	for (size_t i = 0; i < this->firstHalf.size(); ++i)
	{
		std::cout << "firstHalf: " << this->firstHalf[i].first << " " << this->firstHalf[i].second << std::endl;
	}
	for (size_t i = 0; i < this->secondHalf.size(); ++i)
	{
		std::cout << "secondHalf: " << this->secondHalf[i].first << " " << this->secondHalf[i].second << std::endl;
	}
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
	std::cout << GRAY "\nSTEP 4: Create main and lower chain" RESET << std::endl;
	size_t i = 0, j = 0;
	while (i < this->firstHalf.size() && j < this->secondHalf.size())
	{
		if (this->firstHalf[i].first < this->secondHalf[j].first)
		{
			mainChain.push_back(this->firstHalf[i].first);
			lowerChain.push_back(this->firstHalf[i].second);
			++i;
		}
		else
		{
			mainChain.push_back(this->secondHalf[j].first);
			lowerChain.push_back(this->secondHalf[j].second);
			++j;
		}
	}
	while (i < this->firstHalf.size())
	{
		mainChain.push_back(this->firstHalf[i].first);
		lowerChain.push_back(this->firstHalf[i].second);
		++i;
	}
	while (j < this->secondHalf.size())
	{
		mainChain.push_back(this->secondHalf[j].first);
		lowerChain.push_back(this->secondHalf[j].second);
		++j;
	}
	std::cout << "main chain: ";
	for (size_t k = 0; k < mainChain.size(); ++k)
	{
		std::cout << mainChain[k] << " ";
	}
	std::cout << "\nlower chain: ";
	for (size_t k = 0; k < lowerChain.size(); ++k)
	{
		std::cout << lowerChain[k] << " ";
	}
	std::cout << std::endl;
}