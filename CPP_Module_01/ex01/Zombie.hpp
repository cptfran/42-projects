#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class Zombie {

	private:
		std::string name;
		void announce();
		
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
};

Zombie*	zombieHorde(int N, std::string name);

#endif