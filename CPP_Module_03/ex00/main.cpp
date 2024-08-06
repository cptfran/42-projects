#include "ClapTrap.hpp"

int main()
{
    ClapTrap cp1("Mike");
    ClapTrap cp2("Tony");
    cp1.attack("Tony");
    if (cp2.getName() == "Tony")
    {
        cp2.takeDamage(cp1.getAttackDamage());
    }
    return 0;
}
