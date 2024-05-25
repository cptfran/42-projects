#include "Base.hpp"
#include "Colors.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

int main() {
    std::srand(std::time(0));
    Base* randomObj = generate();
    std::cout << LIGHT_GREEN "Identyfing as pointer (void identify(Base* p))" RESET << std::endl;
    identify(randomObj);
    std::cout << LIGHT_PURPLE "Identyfing as refference (void identify(Base& p))" RESET << std::endl;
    identify(*randomObj);
    delete randomObj;
    return 0;
}
