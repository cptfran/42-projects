#include <iostream>
#include "Msg.hpp"
#include "Cure.hpp"

Cure::Cure() : AMateria() {
    std::cout << MSG_CURE_DEFAULT_CONSTRUCTOR << std::endl;
}

Cure::Cure(const std::string &type) : AMateria(type) {
    std::cout << MSG_CURE_ASSIGN_TYPE_CONSTRUCTOR << std::endl;
}

Cure::~Cure() {
    std::cout << MSG_CURE_DESTRUCTOR << std::endl;
}

AMateria* Cure::clone() const {
    return new Cure(this->type);
}

void Cure::use(ICharacter& target) {
    std::cout << YELLOW << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}