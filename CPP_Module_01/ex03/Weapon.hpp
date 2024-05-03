#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <iostream>

class Weapon {

	private:
		std::string type;
	public:
		const std::string&	getType() const { return type; }
		void	setType(const std::string& newType) { type = newType; };
};

class HumanA {

	private:
		Weapon 		weapon;
		std::string name;
	public:
		HumanA(const std::string& name, const std::string &weaponType);
		void	attack() {
			std::cout << name << " attacks with their " << weapon.getType() << std::endl;
		}
};

class HumanB {

	private:
		Weapon 		weapon;
		std::string name;
	public:
		HumanB(const std::string& name, const std::string& weaponType);
		void	attack() {
			std::cout << name << " attacks with their " << weapon.getType() << std::endl;
	}
};


#endif