#include <cstdlib>
#include <iostream>
#include <typeinfo>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Colors.hpp"

Base::~Base() {}

Base* generate() {
    int rollTheDice = std::rand() % 3;
    switch (rollTheDice) {
        case 0:
            return new A;
        case 1:
            return new B;
        case 2:
            return new C;
        default:
            std::cerr << RED "Error: roll the dice failed" RESET << std::endl;
    }
}
// dynamic cast tries to convert to pointer type A, B or C, if succeds, returns pointer to p, if no returns null
void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cerr << RED "Verification error" RESET << std::endl;
    }
}

void identify(Base& p) {
    try {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    } catch (std::exception&) {
        try {
            dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        } catch (std::exception&) {
            try {
                dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            } catch (std::exception&) {
                std::cerr << RED "Verification error" RESET << std::endl;
            }
        }
    }
}