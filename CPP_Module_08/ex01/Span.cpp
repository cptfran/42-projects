#include "Span.hpp"

Span::Span() {}

Span::Span(const unsigned int N) {
    this->data.reserve(N);
}

Span::Span(const Span& toCopy) : data(toCopy.data) {}

Span& Span::operator=(const Span& toCopy) {
    if (this != &toCopy) {
        this->data = toCopy.data;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(const int num) {
    this->data.push_back(num);
}

void Span::shortestSpan() {
    
}

