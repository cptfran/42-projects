#include "WrongCat.hpp"
#include "Msg.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << MSG_WRONG_CAT_DEFAULT_CONSTRUCTOR << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
    std::cout << MSG_WRONG_CAT_COPY_CONSTRUCTOR << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &obj)
{
    if (this != &obj)
    {
        WrongAnimal::operator=(obj);
    }
    std::cout << MSG_WRONG_CAT_COPY_ASSIGNMENT << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << MSG_WRONG_CAT_DESTRUCTOR << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << MSG_WRONG_CAT_SOUND << std::endl;
}