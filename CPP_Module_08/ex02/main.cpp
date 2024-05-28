#include <iostream>
#include <vector>
#include "MutantStack.hpp"
#include "Colors.hpp"

int main() {

    std::cout << LIGHT_GREEN "\nMutant stack:" RESET << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
//[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::cout << LIGHT_GREEN "\nVector:" RESET << std::endl;
    std::vector<int> vecStack;
    vecStack.push_back(5);
    vecStack.push_back(17);
    std::cout << vecStack.back() << std::endl;
    vecStack.pop_back();
    std::cout << vecStack.size() << std::endl;
    vecStack.push_back(3);
    vecStack.push_back(5);
    vecStack.push_back(737);
//[...]
    vecStack.push_back(0);
    std::vector<int>::iterator vIt = vecStack.begin();
    std::vector<int>::iterator vIte = vecStack.end();
    ++vIt;
    --vIt;
    while (vIt != vIte)
    {
        std::cout << *vIt << std::endl;
        ++vIt;
    }
    return 0;
}