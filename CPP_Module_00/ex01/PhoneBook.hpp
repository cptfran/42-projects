#include "colors.h"

class PhoneBook {
	public:
		PhoneBook() : numOfContacts(0), oldestContact(-1) {}
		void	addContact() {
			Contact contact;
			contact.setContact();
			if (numOfContacts < 8) {
				if (oldestContact == -1)
					oldestContact = numOfContacts;
				contacts[numOfContacts] = contact;
				numOfContacts++;
				std::cout << LIGHT_GREEN << "\nCONTACT ADDED\n" << RESET << std::endl;
			} else {
				contacts[oldestContact] = contact;
				if (oldestContact < 7)
					oldestContact++;
				else
					oldestContact = 0;
				std::cout << LIGHT_GREEN << "\nCONTACT REPLACED\n" << RESET << std::endl;
			}
		}
		int	printContactList() {
			if (numOfContacts > 0) {
				printFirstRow();
				for (int i = 0; i < numOfContacts; i++)
					contacts[i].printStartContactInfo(i);
				std::cout << std::endl;
				return 1;
			} else {
				std::cout << RED << "\nCONTACT LIST EMPTY\n" << RESET << std::endl;
				return 0;
			}
		}
		void	printSingleContact(int index_input) { contacts[index_input].printAllContactInfo(); }
		int	getNumOfContacts() { return numOfContacts; }
	private:
		Contact contacts[8];
		int	numOfContacts, oldestContact;
		void	printFirstRow() {
			std::cout << GRAY << '\n' << std::setw(10) << std::right << std::setfill(' ') << "INDEX" << '|'
				<< std::setw(10) << std::right << std::setfill(' ') << "FIRST NAME" << '|'
				<< std::setw(10) << std::right << std::setfill(' ') << "LAST NAME" << '|'
				<< std::setw(10) << std::right << std::setfill(' ') << "NICKNAME" << RESET << std::endl;
		}
};