#include "Animal.hpp"
#include "Msg.hpp"
#include <iostream>

#include "Colors.hpp"

Animal::Animal() {
    std::cout << MSG_DEFAULT_CONSTRUCTOR << std::endl;
}

Animal::Animal(const Animal& obj) : type(obj.type) {
    std::cout << MSG_COPY_CONSTRUCTOR << std::endl;
}

Animal& Animal::operator=(const Animal& obj) {
    if (this != &obj) {
        this->name = obj.name;
    }
    std::cout << MSG_COPY_ASSIGNMENT << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << MSG_DESTRUCTOR << std::endl;
}

void Animal::makeSound() {
    std::cout << MSG_ANIMAL_DEFAULT_SOUND << std::endl;
}


