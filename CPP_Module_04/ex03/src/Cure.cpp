#include <iostream>
#include "../incl/Msg.hpp"
#include "../incl/Cure.hpp"

Cure::Cure() : AMateria("cure") {
    std::cout << MSG_CURE_DEFAULT_CONSTRUCTOR << std::endl;
}

Cure::Cure(const std::string &type) : AMateria(type) {
    std::cout << MSG_CURE_ASSIGN_TYPE_CONSTRUCTOR << std::endl;
}

Cure::~Cure() {
    std::cout << MSG_CURE_DESTRUCTOR << std::endl;
}

AMateria* Cure::clone() const {
    std::cout << MSG_CURE_CLONE << std::endl;
    return new Cure(this->type);
}

void Cure::use(ICharacter& target) {
    std::cout << LIGHT_MAGENTA << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}