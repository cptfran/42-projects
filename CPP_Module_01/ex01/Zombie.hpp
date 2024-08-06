#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <cstdlib>

# define RED "\033[31m"
# define LIGHT_GREEN "\033[92m"
# define BLUE "\033[94m"
# define YELLOW "\033[33m"
# define GRAY "\033[90m"
# define RESET "\033[0m"

class Zombie
{
public:
	Zombie();
	~Zombie();
	void	setName(std::string name);
private:
	std::string zombieName;
	void	 announce();
};

Zombie*	zombieHorde(int N, std::string name);

#endif