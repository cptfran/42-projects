#include "Cat.hpp"
#include "Msg.hpp"
#include <iostream>

Cat::Cat() : Animal()
{
    this->type = "Cat";
    std::cout << MSG_CAT_DEFAULT_CONSTRUCTOR << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
    std::cout << MSG_CAT_COPY_CONSTRUCTOR << std::endl;
}

Cat& Cat::operator=(const Cat &obj)
{
    if (this != &obj)
    {
        Animal::operator=(obj);
    }
    std::cout << MSG_CAT_COPY_ASSIGNMENT << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << MSG_CAT_DESTRUCTOR << std::endl;
}

void Cat::makeSound() const
{
    std::cout << MSG_CAT_SOUND << std::endl;
}