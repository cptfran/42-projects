#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>

class Span {
public:
    Span();
    Span(const unsigned int N);
    Span(const Span& toCopy);
    Span& operator=(const Span& toCopy);
    ~Span();
    void addNumber(const int num);
    void shortestSpan();
    void longestSpan();
private:
    std::vector<int> data;
};

#endif