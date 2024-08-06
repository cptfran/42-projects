#include "FragTrap.hpp"
#include "Colors.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << LIGHT_GREEN << "Default FragTrap has joined the battlefield" << RESET << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    std::cout << LIGHT_GREEN << "FragTrap " << this->name << " has joined the battlefield" << RESET << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj)
{
    std::cout << LIGHT_GREEN << "FragTrap " << this->name << " has been cloned" << RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
    std::cout << LIGHT_GREEN << "FragTrap " << this->name << " Copy assignment operator called" << RESET << std::endl;
    if (this != &obj)
    {
        ClapTrap::operator=(obj);
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << RED << "FragTrap " << this->name << " has left the battlefield" << RESET << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << YELLOW << "FragTrap " << this->name << " high fives" << RESET << std::endl;
}
