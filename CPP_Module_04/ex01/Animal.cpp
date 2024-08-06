#include "Animal.hpp"
#include "Msg.hpp"
#include "Colors.hpp"
#include <iostream>

Animal::Animal() : type("default")
{
    std::cout << MSG_ANIMAL_DEFAULT_CONSTRUCTOR << std::endl;
}

Animal::Animal(const Animal& obj) : type(obj.type)
{
    std::cout << MSG_ANIMAL_COPY_CONSTRUCTOR << std::endl;
}

Animal& Animal::operator=(const Animal& obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    std::cout << MSG_ANIMAL_COPY_ASSIGNMENT << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << MSG_ANIMAL_DESTRUCTOR << std::endl;
}

void Animal::makeSound() const
{
    std::cout << MSG_ANIMAL_DEFAULT_SOUND << std::endl;
}

const std::string& Animal::getType() const
{
    return this->type;
}
