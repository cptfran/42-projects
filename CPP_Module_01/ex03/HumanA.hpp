#include "Weapon.hpp"

class HumanA
{
public:
	HumanA(const std::string &name, Weapon &weapon);
	void setWeapon(Weapon &newWeapon);
	void attack();
private:
	std::string name;
	Weapon &weapon;
};