#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(const std::string& name);
    ScavTrap(const ScavTrap& obj);
    ScavTrap& operator=(const ScavTrap& obj);
    ~ScavTrap();
    void attack(const std::string& target);
    void guardGate();
protected:
    static const unsigned int defHitPoints = 100;
    static const unsigned int defEnergyPoints = 50;
    static const unsigned int defAttackDamage = 20;
};

#endif