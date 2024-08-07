#include <algorithm>
#include <limits>
#include <stdexcept>
#include "Span.hpp"

Span::Span() {}

Span::Span(const unsigned int& N)
{
    this->data.reserve(N);
}

Span::Span(const Span& toCopy) : data(toCopy.data) {}

Span& Span::operator=(const Span& toCopy)
{
    if (this != &toCopy)
    {
        this->data = toCopy.data;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(const int& num)
{
    this->data.push_back(num);
}

int Span::shortestSpan()
{
    if (this->data.size() < 2)
    {
        throw std::logic_error("Not enough elements to compare");
    }
    std::vector<int> tmpData = this->data;
    std::sort(tmpData.begin(), tmpData.end());
    int shortestSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < tmpData.size(); i++)
    {
        int currentSpan = tmpData[i] - tmpData[i - 1];
        if (currentSpan < shortestSpan)
        {
            shortestSpan = currentSpan;
        }
    }
    return shortestSpan;
}

int Span::longestSpan()
{
    if (this->data.size() < 2)
    {
        throw std::logic_error("Not enough elements to compare");
    }
    return *std::max_element(this->data.begin(), this->data.end())
            - *std::min_element(this->data.begin(), this->data.end());
}