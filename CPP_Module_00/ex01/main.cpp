#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdlib>
#define RED "\033[31m"
#define GREEN "\033[32m"
#define LIGHT_GREEN "\033[92m"
#define BLUE "\033[94m"
#define YELLOW "\033[33m"
#define GRAY "\033[90m"
#define RESET "\033[0m"

int	main() {
	PhoneBook phoneBook;
	std::string input;
	std::cout << "\n\n\n" << std::endl;
	while (1) {
		std::cout << BLUE << "PHONEBOOK: " << RESET;
		std::cin >> input;
		if (input == "EXIT") {
			std::cout << YELLOW << "GOODBYE" << RESET << std::endl;
			exit(0);
		} else if (input == "ADD") {
			Contact contact;
			contact.setContact();
			contact.printContact();
		} else if (!input.empty()) {
			std::cout << RED << "\nUNKNOWN COMMAND: "<< input << RESET << std::endl;
			std::cout << GRAY << "(AVAILABLE COMMANDS: 'ADD', 'SEARCH', 'EXIT')\n" << RESET << std::endl;
		}
	}

	return 0;
}