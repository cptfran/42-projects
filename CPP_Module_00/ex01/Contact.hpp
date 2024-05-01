#include <iostream>
#include <iomanip>
#include "colors.h"

class Contact {
	public:
		void	setContact() {
				std::string	input;
				std::cout << '\n' << GRAY << "Enter first name: "<< RESET;
				std::cin >> input;
				setFirstName(input);
				std::cout << GRAY << "Enter last name: "<< RESET;
				std::cin >> input;
				setLastName(input);
				std::cout << GRAY << "Enter nickname: "<< RESET;
				std::cin >> input;
				setNickname(input);
				std::cout << GRAY << "Enter phone number: "<< RESET;
				std::cin >> input;
				setPhoneNumber(input);
				std::cout << GRAY << "Enter your darkest secret: " << RESET;
				std::cin >> input;
				setDarkestSecret(input);
		}
		void	printStartContactInfo(const int i) {
			std::cout << std::setw(10) << std::right << std::setfill(' ') << i << GRAY << '|' << RESET
				<< std::setw(10) << std::right << std::setfill(' ') << truncateString(firstName) << GRAY << '|' << RESET
				<< std::setw(10) << std::right << std::setfill(' ') << truncateString(lastName) << GRAY << '|' << RESET
				<< std::setw(10) << std::right << std::setfill(' ') << truncateString(nickname) << RESET << std::endl;
		}
		void	printAllContactInfo() {
			std::cout << "\n" << GRAY << "FIRST NAME: " << RESET << firstName << "\n" << GRAY << "LAST NAME: "
				<< RESET << lastName << "\n" << GRAY << "NICKNAME: " << RESET << nickname << "\n" << GRAY
				<< "PHONE NUMBER: " << RESET << phoneNumber << "\n" << GRAY << "DARKEST SECRET: " << RESET
				<< darkestSecret << "\n" << std::endl;
		}
	private:
		std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
		void	setFirstName(const std::string& name) { firstName = name; }
		void	setLastName(const std::string& name) { lastName = name; }
		void	setNickname(const std::string& name) { nickname = name; }
		void	setPhoneNumber(std::string& number) {
			while (!isDigitStr(number)) {
				std::cout << RED << "\nUSE ONLY DIGITS\n" << RESET << std::endl;
				std::cout << GRAY << "Enter phone number: "<< RESET;
				std::cin >> number;
			}
			phoneNumber = number;
		}
		void	setDarkestSecret(const std::string& secret) { darkestSecret  = secret; }
		bool	isDigitStr(const std::string& str) {
			for (std::string::const_iterator i = str.begin(); i != str.end(); i++) {
				if (!isdigit(*i))
					return false;
			}
			return true;
		}
		std::string	truncateString(std::string str) {
			if (str.length() >= 10)
				return str.substr(0, 9) + ".";
			else
				return str;
		}
};