#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "colors.h"
#include <cstdlib>
#include <limits>
#include <sstream>

int	main()
{
	PhoneBook phoneBook;
	std::string input;
	std::cout << std::endl;
	while (true)
	{
		std::cout << BLUE << "PHONEBOOK" << YELLOW << " (" << phoneBook.getNumOfContacts() << " contacts)"
			<< BLUE << ": " << RESET;
		std::getline(std::cin, input);
		if (input == "EXIT")
		{
			std::cout << YELLOW << "\nGOODBYE\n" << RESET << std::endl;
			exit(0);
		}
		if (input == "ADD")
		{
			phoneBook.addContact();
		}
		else if (input == "SEARCH")
		{
			if (phoneBook.printContactList())
			{
	            int index_input;
	            while (true)
	            {
	                std::cout << GRAY << "Enter index to display a contact: " << RESET;
	                std::getline(std::cin, input);
	                std::istringstream iss(input);
	                if (iss >> index_input && !(index_input < 0 || index_input >= phoneBook.getNumOfContacts()))
	                {
		                 break;
	                }
	                std::cout << RED << "\nCONTACT DOESN'T EXIST\n" << RESET << std::endl;
	            }
				phoneBook.printSingleContact(index_input);
			}
		}
		else if (!input.empty())
		{
			std::cout << RED << "\nUNKNOWN COMMAND: "<< input << RESET << std::endl;
			std::cout << GRAY << "(AVAILABLE COMMANDS: 'ADD', 'SEARCH', 'EXIT')\n" << RESET << std::endl;
		}
	}
	return 0;
}