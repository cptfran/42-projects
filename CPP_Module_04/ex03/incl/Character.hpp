#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "ICharacter.hpp"

class Character : public ICharacter
{
public:
    Character();
    Character(const std::string& name);
    Character(const Character& obj);
    Character& operator=(const Character& obj);
    ~Character();
    const std::string& getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
private:
    std::string name;
    AMateria* slot[4];
};

#endif