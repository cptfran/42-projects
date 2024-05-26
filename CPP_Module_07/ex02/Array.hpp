#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <cstddef>
#include <exception>

template <typename T>
class Array {
public:
    Array() : arr(NULL), n(0) {}
    Array(const unsigned int& n) : arr(new T[n]), n(n) {}
    Array(const Array& toCopy) : arr(new T[toCopy.n]), n(toCopy.n) {
        for (unsigned int i = 0; i < toCopy.n; i++) {
            this->arr[i] = toCopy.arr[i];
        }
    }
    Array& operator=(const Array& toCopy) {
        if (this != &toCopy) {
            delete[] this->arr;
            this->arr = new T[toCopy.n];
            this->n = toCopy.n;
            for (unsigned int i = 0; i < n; i++) {
                this->arr[i] = toCopy.arr[i];
            }
        }
        return *this;
    }
    ~Array() {
        delete[] arr;
    }
    T& operator[](const unsigned int n) {
        if (n >= this->n) {
            throw std::exception();
        }
        return this->arr[n];
    }
    const unsigned int& size() const {
        return n;
    }
private:
    T* arr;
    unsigned int n;
};

#endif