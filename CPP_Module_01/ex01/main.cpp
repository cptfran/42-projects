#include "Zombie.hpp"

int	main(int argc, char **argv) {
	if (argc != 3) {
		std::cerr << YELLOW << "\nUsage: " << argv[0] << LIGHT_GREEN << " [number_of_zombies]" << BLUE << "[zombie_name];" << RESET << std::endl;
		return 1;
	}
	std::cout << std::endl;
	std::string strN = argv[1];
	int N = std::atoi(strN.c_str());
	if (N < 1) {
		std::cerr << RED << "\nFirst arg has to be 1 or more" << RESET << std::endl;
		return 1;
	}
	std::cout << LIGHT_GREEN;
	Zombie *horde = zombieHorde(N, argv[2]);
	std::cout << RESET;
	std::string input;
	while (1) {
		std::cout << YELLOW << "\nKill the zombies? (y/n)" << RESET << std::endl;
		std::getline(std::cin, input);
		if (input == "y") {
			std::cout << LIGHT_GREEN << "\n";
			delete[] horde;
			std::cout << RESET;
			break;
		} else {
			if (input == "n") {
				std::cout << RED << "\nYou will have memory leaks, pick 'y'" << RESET << std::endl;
			} else
				std::cout << RED << "\nChoose 'y' or 'n'" << RESET << std::endl;
			continue;
		}
	}
	return 0;
}