#include "Zombie.hpp"

int	main(int argc, char **argv)
{
	std::string input;
	if (argc < 2)
	{
		std::cerr << RED << "\nError: enter at least one argument to create object" << RESET << std::endl;
		exit(1);
	}
	++argv;
	while (true)
	{
		std::cout << BLUE << "\nAllocate on the stack or heap? ➡️  " << RESET;
		std::getline(std::cin, input);
		if (input == "stack" || input == "heap")
		{
			break;
		}
		std::cout << RED << "Error: enter \'stack\' or \'heap\''" << RESET << std::endl;
	}
	if (input == "heap")
	{
		Zombie **zombies = new Zombie*[argc - 1];
		std::cout << YELLOW << "\nInitiating objects on the heap \n\n⬇️  ⬇️  ⬇️  ⬇️  ⬇️  ⬇️  ⬇️  ⬇️  ⬇️  ⬇️\n" 
			<< LIGHT_GREEN << std::endl;
		for (int i = 0; i < argc - 1; i++)
		{
			zombies[i] = newZombie(argv[i]);
		}
		for (int i = 0; i < argc - 1; i++)
		{
			delete zombies[i];
		}
		delete[] zombies;
		std::cout << RESET;
	}
	else if (input == "stack")
	{
		std::cout << GRAY << "\nInitiating objects on the stack \n⬇️  ⬇️  ⬇️  ⬇️  ⬇️  ⬇️  ⬇️  ⬇️  ⬇️  ⬇️\n" 
			<< LIGHT_GREEN << std::endl;
		for(int i = 0; i < argc - 1; i++)
		{
			randomChump(argv[i]);
		}
		std::cout << RESET;
	}
	return 0;
}