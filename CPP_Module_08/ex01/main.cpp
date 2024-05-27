#include <iostream>
#include "Span.hpp"
#include "Colors.hpp"

int main()
{
    try {
        std::vector<int> numbers;
        for (int i = 1; i <= 1000; i++) {
            numbers.push_back(i);
        }
        Span numbersObj(1000);
        numbersObj.addNumbersByRangeOfIterators(numbers.begin(), numbers.end());
        std::cout << LIGHT_GREEN << "Shortest span: " << numbersObj.shortestSpan() << std::endl;
        std::cout << "Longest span: " << numbersObj.longestSpan() << RESET << std::endl;
    } catch (const std::length_error& e) {
        std::cerr << RED << e.what() << std::endl;
    }
    return 0;
}