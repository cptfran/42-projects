#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
    Cure();
    Cure(const std::string& type);
    ~Cure();
    AMateria* clone() const;
    void use(ICharacter& target);
};

#endif