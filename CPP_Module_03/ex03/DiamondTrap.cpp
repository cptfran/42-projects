#include "DiamondTrap.hpp"
#include "Colors.hpp"

DiamondTrap::DiamondTrap() {
    std::cout << LIGHT_GREEN << "Default DiamondTrap has joined the battlefield" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
    std::cout << LIGHT_GREEN << "DiamondTrap " << this->name << " has joined the battlefield" << RESET << std::endl;
    this->name = name;
    this->hitPoints = FragTrap::defHitPoints;
    this->energyPoints = ScavTrap::defEnergyPoints;
    this->attackDamage = FragTrap::defAttackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : ClapTrap(obj), ScavTrap(obj), FragTrap(obj) {
    std::cout << LIGHT_GREEN << "DiamondTrap " << this->name << " has been cloned" << RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj) {
    std::cout << LIGHT_GREEN << "DiamondTrap " << this->name << " Copy assignment operator called" << RESET << std::endl;
    if (this != &obj) {
        ClapTrap::operator=(obj);
    }
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << RED << "DiamondTrap " << this->name << " has left the battlefield" << RESET << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << YELLOW <<  "DiamondTrap name: " << this->name << "\nClapTrap name: " << ClapTrap::name << RESET << std::endl;
}