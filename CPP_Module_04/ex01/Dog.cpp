#include "Dog.hpp"
#include "Msg.hpp"
#include <iostream>

Dog::Dog() : Animal() {
    this->type = "Dog";
    std::cout << MSG_DOG_DEFAULT_CONSTRUCTOR << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj) {
    std::cout << MSG_DOG_COPY_CONSTRUCTOR << std::endl;
}

Dog& Dog::operator=(const Dog &obj) {
    if (this != &obj) {
        Animal::operator=(obj);
    }
    std::cout << MSG_DOG_COPY_ASSIGNMENT << std::endl;
    return *this;
}

Dog::~Dog() {
    std::cout << MSG_DOG_DESTRUCTOR << std::endl;
}

void Dog::makeSound() const {
    std::cout << MSG_DOG_SOUND << std::endl;
}