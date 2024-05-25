#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T>
void printArg(T arg) {
    std::cout << arg << std::endl;
}

template <typename T>
void iter(T* arrAddress, const size_t arrLen, void (*func)(T)) {
    for (size_t i = 0; i < arrLen; i++) {
        func(arrAddress[i]);
    }
}

#endif