#include "ScavTrap.hpp"
#include "Colors.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << LIGHT_GREEN << "Default ScavTrap has joined the battlefield" << RESET << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    std::cout << LIGHT_GREEN << "ScavTrap " << this->name << " has joined the battlefield" << RESET << std::endl;
    this->hitPoints = ScavTrap::defHitPoints;
    this->energyPoints = ScavTrap::defEnergyPoints;
    this->attackDamage = ScavTrap::defAttackDamage;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj) {
    std::cout << LIGHT_GREEN << "ScavTrap " << this->name << " has been cloned" << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj) {
    std::cout << LIGHT_GREEN << "ScavTrap " << this->name << " Copy assignment operator called" << RESET << std::endl;
    if (this != &obj) {
        ClapTrap::operator=(obj);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << RED << "ScavTrap " << this->name << " has left the battlefield" << RESET << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (this->energyPoints > 0) {
        std::cout << YELLOW << "ScavTrap " << this->name << " attacks " << target << ", causing "
            << this->attackDamage << " points of damage! ⚔️" << RESET << std::endl;
        --this->energyPoints;
    } else {
        std::cout << YELLOW << "ScavTrap " << this->name << " is out of energy" << RESET << std::endl;
    }
}

void ScavTrap::guardGate() {
    std::cout << YELLOW << "ScavTrap " << this->name << " is in the Gate keeper mode 🛡️" << RESET << std::endl;
}
