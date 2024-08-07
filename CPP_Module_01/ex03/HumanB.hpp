#include "Weapon.hpp"

class HumanB
{
public:
	HumanB(const std::string &name);
	void setWeapon(Weapon &weapon_obj);
	void attack();
private:
	std::string name;
	Weapon *weapon;
};