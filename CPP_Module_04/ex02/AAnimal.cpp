#include "AAnimal.hpp"
#include "Msg.hpp"
#include "Colors.hpp"
#include <iostream>

AAnimal::AAnimal() : type("default")
{
    std::cout << MSG_AANIMAL_DEFAULT_CONSTRUCTOR << std::endl;
}

AAnimal::AAnimal(const AAnimal& obj) : type(obj.type)
{
    std::cout << MSG_AANIMAL_COPY_CONSTRUCTOR << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    std::cout << MSG_AANIMAL_COPY_ASSIGNMENT << std::endl;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << MSG_AANIMAL_DESTRUCTOR << std::endl;
}

const std::string& AAnimal::getType() const
{
    return this->type;
}
