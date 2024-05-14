#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap {
public:
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& obj);
	ClapTrap& operator=(const ClapTrap& obj);
	virtual ~ClapTrap();
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	std::string& getName();
	unsigned int& getHitPoints();
	unsigned int& getEnergyPoints();
	unsigned int& getAttackDamage();
	void setName(const std::string& name);
	void setHitPoints(const unsigned int& hitPoints);
	void setEnergyPoints(const unsigned int& energyPoints);
	void setAttackDamage(const unsigned int& attackDamage);
protected:
	std::string name;
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;
};

#endif