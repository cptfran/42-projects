#include <iostream>
#include "../incl/AMateria.hpp"
#include "../incl/Msg.hpp"

AMateria::AMateria() {
    std::cout << MSG_AMATERIA_DEFAULT_CONSTRUCTOR << std::endl;
}

AMateria::AMateria(const std::string& type) : type(type) {
    std::cout << MSG_AMATERIA_ASSIGN_TYPE_CONSTRUCTOR << std::endl;
}

AMateria::~AMateria() {
    std::cout << MSG_AMATERIA_DESTRUCTOR << std::endl;
}

const std::string& AMateria::getType() const {
    return this->type;
}

void AMateria::use(ICharacter& target) {
    std::cout << MSG_AMATERIA_USE_DEFAULT << target.getName() << std::endl;
}