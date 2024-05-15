#include "Cat.hpp"
#include "Msg.hpp"
#include <iostream>

Cat::Cat() : Animal() {
    this->type = "Cat";
    this->brain = new Brain;
    std::cout << MSG_CAT_DEFAULT_CONSTRUCTOR << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj) {
    this->type = obj.type;
    this->brain = new Brain(*obj.brain);
    std::cout << MSG_CAT_COPY_CONSTRUCTOR << std::endl;
}

Cat& Cat::operator=(const Cat &obj) {
    if (this != &obj) {
        this->type = obj.type;
        delete this->brain;
        this->brain = new Brain(*obj.brain);
        Animal::operator=(obj);
    }
    std::cout << MSG_CAT_COPY_ASSIGNMENT << std::endl;
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << MSG_CAT_DESTRUCTOR << std::endl;
}

void Cat::makeSound() const {
    std::cout << MSG_CAT_SOUND << std::endl;
}

void Cat::setBrainIdeas(const std::string* newIdeas, int size) {
    this->brain->setIdeas(newIdeas, size);
}

std::string* Cat::getBrainIdeas() {
    return this->brain->getIdeas();
}