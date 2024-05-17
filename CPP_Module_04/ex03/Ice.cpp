#include <iostream>
#include "Msg.hpp"
#include "Ice.hpp"

Ice::Ice() : AMateria() {
    std::cout << MSG_ICE_DEFAULT_CONSTRUCTOR << std::endl;
}

Ice::Ice(const std::string &type) : AMateria(type) {
    std::cout << MSG_ICE_ASSIGN_TYPE_CONSTRUCTOR << std::endl;
}

Ice::~Ice() {
    std::cout << MSG_ICE_DESTRUCTOR << std::endl;
}

AMateria* Ice::clone() const {
    return new Ice(this->type);
}

void Ice::use(ICharacter& target) {
    std::cout << YELLOW << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}