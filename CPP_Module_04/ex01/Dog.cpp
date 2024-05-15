#include "Dog.hpp"
#include "Msg.hpp"
#include <iostream>

Dog::Dog() : Animal() {
    this->type = "Dog";
    this->brain = new Brain;
    std::cout << MSG_DOG_DEFAULT_CONSTRUCTOR << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj) {
    this->type = obj.type;
    this->brain = new Brain(*obj.brain);
    std::cout << MSG_DOG_COPY_CONSTRUCTOR << std::endl;
}

Dog& Dog::operator=(const Dog &obj) {
    if (this != &obj) {
        this->type = obj.type;
        delete this->brain;
        this->brain = new Brain(*obj.brain);
        Animal::operator=(obj);
    }
    std::cout << MSG_DOG_COPY_ASSIGNMENT << std::endl;
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << MSG_DOG_DESTRUCTOR << std::endl;
}

void Dog::makeSound() const {
    std::cout << MSG_DOG_SOUND << std::endl;
}

void Dog::setBrainIdeas(const std::string* newIdeas, int size) {
    this->brain->setIdeas(newIdeas, size);
}

std::string* Dog::getBrainIdeas() {
    return this->brain->getIdeas();
}