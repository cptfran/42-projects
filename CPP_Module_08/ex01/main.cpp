#include <iostream>
#include <vector>
#include "easyfind.hpp"
#include "Colors.hpp"

int main() {
    std::vector<int> intVec;
    intVec.push_back(1);
    intVec.push_back(2);
    intVec.push_back(3);
    intVec.push_back(4);
    intVec.push_back(5);
    try {
        const std::vector<int>::iterator it = easyfind(intVec, 3);
        std::cout << "Found number: " << *it << std::endl;
        (void)it;
    } catch (std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
    try {
        const std::vector<int>::iterator it = easyfind(intVec, 6);
        std::cout << "Found number: " << *it << std::endl;
        (void)it;
    } catch (std::exception& e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    }
}