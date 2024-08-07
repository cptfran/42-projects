#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <iostream>

class Span
{
public:
    Span();
    Span(const unsigned int& N);
    Span(const Span& toCopy);
    Span& operator=(const Span& toCopy);
    ~Span();
    void addNumber(const int& num);
    template <typename T>
    void addNumbersByRangeOfIterators(T begin, T end)
    {
        if (static_cast<std::size_t>(std::distance(begin, end)) > data.capacity() - data.size())
        {
            std::cout << static_cast<std::size_t>(std::distance(begin, end)) << std::endl;
            std::cout << data.capacity() - data.size() << std::endl;
            throw std::length_error("Data capacity to small, choose smaller range");
        }
        while (begin != end)
        {
            this->data.push_back(*begin);
            ++begin;
        }
    }
    int shortestSpan();
    int longestSpan();
private:
    std::vector<int> data;
};

#endif