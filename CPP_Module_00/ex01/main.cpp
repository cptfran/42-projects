#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "colors.h"
#include <cstdlib>
#include <limits>

int	main() {
	PhoneBook phoneBook;
	std::string input;
	std::cout << std::endl;
	while (1) {
		std::cout << BLUE << "PHONEBOOK: " << RESET;
		std::cin >> input;
		if (input == "EXIT") {
			std::cout << YELLOW << "\nGOODBYE\n" << RESET << std::endl;
			exit(0);
		} else if (input == "ADD") {
			phoneBook.addContact();
		} else if (input == "SEARCH") {
			if (phoneBook.printContactList()) {
				std::cout << GRAY << "Enter index to display a contact: " << RESET;
				int	index_input;
				std::cin >> index_input;
				while (std::cin.fail() || index_input < 0 || index_input >= phoneBook.getNumOfContacts()) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << RED << "\nCONTACT DOESN'T EXIST\n" << RESET << std::endl;
					std::cout << GRAY << "Enter index to display a contact: " << RESET;
					std::cin >> index_input;
				}
				phoneBook.printSingleContact(index_input);
			}
		} else if (!input.empty()) {
			std::cout << RED << "\nUNKNOWN COMMAND: "<< input << RESET << std::endl;
			std::cout << GRAY << "(AVAILABLE COMMANDS: 'ADD', 'SEARCH', 'EXIT')\n" << RESET << std::endl;
		}
	}

	return 0;
}