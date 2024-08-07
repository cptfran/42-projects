#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();
	void addContact();
	int printContactList();
	void printSingleContact(int index_input);
	int getNumOfContacts();

private:
	Contact contacts[8];
	int numOfContacts, oldestContact;
	void printFirstRow();
};

#endif // PHONEBOOK_HPP