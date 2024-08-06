#include "Zombie.hpp"

void	Zombie::announce()
{
    std::cout << zombieName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie() {}

Zombie::~Zombie()
{
    std::cout << zombieName << " has been destroyed" << std::endl;
}

void	Zombie::setName(std::string name)
{
    zombieName = name; announce();
}