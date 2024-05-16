#include <iostream>
#include "AMateria.hpp"
#include "Msg.hpp"

AMateria::AMateria() {
    std::cout << MSG_AMATERIA_DEFAULT_CONSTRUCTOR << std::endl;
}

AMateria::AMateria(const std::string& type) : type(type) {
    std::cout << MSG_AMATERIA_ASSIGN_TYPE_CONSTRUCTOR << std::endl;
}

AMateria::AMateria(const AMateria &obj) : type(obj.type) {
    std::cout << MSG_AMATERIA_COPY_CONSTRUCTOR << std::endl;
}

AMateria& AMateria::operator=(const AMateria &obj) {
    if (this != &obj) {
        this->type = obj.type;
    }
    std::cout << MSG_AMATERIA_COPY_ASSIGNMENT << std::endl;
    return *this;
}

AMateria::~AMateria() {
    std::cout << MSG_AMATERIA_DESTRUCTOR << std::endl;
}

const std::string& AMateria::getType() const {
    return this->type;
}