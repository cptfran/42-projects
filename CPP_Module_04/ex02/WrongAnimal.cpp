#include "WrongAnimal.hpp"
#include "Msg.hpp"
#include "Colors.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("default")
{
    std::cout << MSG_WRONG_ANIMAL_DEFAULT_CONSTRUCTOR << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj) : type(obj.type)
{
    std::cout << MSG_WRONG_ANIMAL_COPY_CONSTRUCTOR << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    std::cout << MSG_WRONG_ANIMAL_COPY_ASSIGNMENT << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << MSG_WRONG_ANIMAL_DESTRUCTOR << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << MSG_WRONG_ANIMAL_DEFAULT_SOUND << std::endl;
}

const std::string& WrongAnimal::getType() const
{
    return this->type;
}
