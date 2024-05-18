#include <iostream>
#include "../incl/MateriaSource.hpp"
#include "../incl/Msg.hpp"

MateriaSource::MateriaSource() : slot() {
    std::cout << MSG_MATERIASOURCE_DEFAULT_CONSTRUCTOR << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& obj) : slot() {
    for (int i = 0; i < 4; i++) {
        if (obj.slot[i]) {
            this->slot[i] = obj.slot[i]->clone();
        }
    }
    std::cout << MSG_MATERIASOURCE_COPY_CONSTRUCTOR << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &obj) {
    if (this != &obj) {
        for (int i = 0; i < 4; i++) {
            if (this->slot[i]) {
                delete this->slot[i];
            }
            if (obj.slot[i]) {
                this->slot[i] = obj.slot[i]->clone();
            } else {
                this->slot[i] = NULL;
            }
        }
    }
    std::cout << MSG_MATERIASOURCE_COPY_ASSIGNMENT << std::endl;
    return *this;
}

MateriaSource::~MateriaSource() {
    std::cout << MSG_MATERIASOURCE_DESTRUCTOR << std::endl;
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (this->slot[i] == NULL && m != NULL) {
            std::cout << MSG_MATERIASOURCE_LEARN_MATERIA << std::endl;
            this->slot[i] = m->clone();
            return;
        }
    }
    std::cerr << ERR_MATERIASOURCE_LEARN_MATERIA << std::endl;
}

AMateria* MateriaSource::createMateria(const std::string &type) {
    for (int i = 0; i < 4; i++) {
        if (this->slot[i] != NULL && this->slot[i]->getType() == type) {
            std::cout << MSG_MATERIASOURCE_CREATE_MATERIA << std::endl;
            return this->slot[i];
        }
    }
    std::cerr << ERR_MATERIASOURCE_CREATE_MATERIA << std::endl;
    return 0;
}