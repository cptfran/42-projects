#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : name(name) {}

void HumanB::setWeapon(Weapon &newWeapon)
{
    weapon = &newWeapon;
}

void HumanB::attack()
{
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}