#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << LIGHT_GREEN << "Default ClapTrap has joined the battlefield" << RESET << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << LIGHT_GREEN << this->name << " has joined the battlefield" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj) : name(obj.name), hitPoints(obj.hitPoints), energyPoints(obj.energyPoints),
	attackDamage(obj.attackDamage) {}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	if (this != &obj)
	{
		this->name = obj.name;
		this->hitPoints = obj.hitPoints;
		this->energyPoints = obj.energyPoints;
		this->attackDamage = obj.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED << this->name << " has left the battlefield" << RESET << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->energyPoints > 0)
	{
		std::cout << YELLOW << "ClapTrap " << this->name << " attacks " << target << " , causing "
			<< this->attackDamage << " points of damage!" << RESET << std::endl;
			this->energyPoints--;
	}
	else
	{
		std::cout << YELLOW << "ClapTrap " << this->name << " is out of energy" << RESET << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints > 0)
	{
		std::cout << RED << "ClapTrap " << this->name << " takes " << amount << " damage" << RESET << std::endl;
		if (amount > this->hitPoints)
		{
			this->hitPoints = 0;
		}
		else
		{
			this->hitPoints -= amount;
		}
		if (this->hitPoints == 0)
		{
			std::cout << RED << "ClapTrap " << this->name << " has died" << RESET << std::endl;
		}
	}
	else
	{
		std::cout << YELLOW << "ClapTrap " << this->name << " is already dead" << RESET << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints < 10)
	{
		std::cout << LIGHT_GREEN << "ClapTrap " << this->name << " repairs " << amount << " hit points" << RESET << std::endl;
		this->hitPoints += amount;
		if (this->hitPoints > 10)
		{
			this->hitPoints = 10;
		}
		this->energyPoints--;
	}
	else
	{
		std::cout << YELLOW << "ClapTrap " << this->name << " is full HP" << RESET << std::endl;
	}
}

unsigned int& ClapTrap::getAttackDamage()
{
	return this->attackDamage;
}

std::string& ClapTrap::getName()
{
	return this->name;
}
