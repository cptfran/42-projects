#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

# define RED "\033[31m"
# define LIGHT_GREEN "\033[92m"
# define BLUE "\033[94m"
# define YELLOW "\033[33m"
# define GRAY "\033[90m"
# define RESET "\033[0m"

class ClapTrap {
public:
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& obj);
	ClapTrap& operator=(const ClapTrap& obj);
	~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	unsigned int& getAttackDamage();
	std::string& getName();
private:
	std::string name;
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;
};

#endif