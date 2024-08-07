#include <iostream>
#include "../incl/Msg.hpp"
#include "../incl/Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << MSG_ICE_DEFAULT_CONSTRUCTOR << std::endl;
}

Ice::Ice(const std::string &type) : AMateria(type)
{
    std::cout << MSG_ICE_ASSIGN_TYPE_CONSTRUCTOR << std::endl;
}

Ice::~Ice()
{
    std::cout << MSG_ICE_DESTRUCTOR << std::endl;
}

AMateria* Ice::clone() const
{
    std::cout << MSG_ICE_CLONE << std::endl;
    return new Ice(this->type);
}

void Ice::use(ICharacter& target)
{
    std::cout << LIGHT_CYAN << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}
