#include "Zombie.hpp"

int	main(int argc, char **argv) {
	
	if (argc != 3) {
		std::cerr << "Usage: " << argv[0] << " [number_of_zombies] [zombie_name]\n";
		return 1;
	}

	Zombie *horde = zombieHorde(atoi(argv[1]), argv[2]);
	delete[] horde;

	return 0;
}