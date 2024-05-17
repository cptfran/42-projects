#include <iostream>
#include "Character.hpp"
#include "Msg.hpp"

Character::Character() : name("unnamed"), slot() {
    std::cout << MSG_CHARACTER_DEFAULT_CONSTRUCTOR << std::endl;
}

Character::Character(const std::string& name) : name(name), slot() {
    std::cout << MSG_CHARACTER_ASSIGN_TYPE_CONSTRUCTOR << std::endl;
}

Character::Character(const Character& obj) : name(obj.name), slot() {
    for (int i = 0; i < 4; i++) {
        if (obj.slot[i]) {
            this->slot[i] = obj.slot[i]->clone();
        }
    }
    std::cout << MSG_CHARACTER_COPY_CONSTRUCTOR << std::endl;
}

Character& Character::operator=(const Character &obj) {
    if (this != &obj) {
        this->name = obj.name;
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
    std::cout << MSG_CHARACTER_COPY_ASSIGNMENT << std::endl;
    return *this;
}

Character::~Character() {
    std::cout << MSG_CHARACTER_DESTRUCTOR << std::endl;
}

const std::string& Character::getName() const {
    return this->name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (this->slot[i] == NULL && m != NULL) {
            this->slot[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && this->slot[idx] != NULL) {
        this->slot[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && this->slot[idx] != NULL) {
        this->slot[idx]->use(target);
    }
}