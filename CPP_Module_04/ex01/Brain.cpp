#include "Brain.hpp"
#include "Msg.hpp"
#include <iostream>

Brain::Brain() {
    this->ideas[0] = "eat";
    this->ideas[1] = "sleep";
    this->ideas[2] = "run";
    std::cout << MSG_BRAIN_DEFAULT_CONSTRUCTOR << std::endl;
}

Brain::Brain(const Brain& obj) {
    for (int i = 0; i < 100; ++i) {
        if (obj.ideas[i].empty())
            break;
        this->ideas[i] = obj.ideas[i];
    }
    std::cout << MSG_BRAIN_COPY_CONSTRUCTOR << std::endl;
}

Brain& Brain::operator=(const Brain &obj) {
    if (this != &obj) {
        for (int i = 0; i < 100; ++i) {
            this->ideas[i] = obj.ideas[i];
        }
    }
    std::cout << MSG_BRAIN_COPY_ASSIGNMENT << std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << MSG_BRAIN_DESTRUCTOR << std::endl;
}

void Brain::setIdeas(const std::string* newIdeas, int size) {
    for (int i = 0; i < size; i++) {
        this->ideas[i] = newIdeas[i];
    }
}

std::string* Brain::getIdeas() {
    return this->ideas;
}