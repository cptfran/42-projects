#include <iostream>

class Contact {
	public:
		void	setContact() {
				std::string	input;
				std::cout << "Enter first name: ";
				std::cin >> input;
				setFirstName(input);
				std::cout << "Enter last name: ";
				std::cin >> input;
				setLastName(input);
				std::cout << "Enter nickname: ";
				std::cin >> input;
				setNickname(input);
				std::cout << "Enter phone number: ";
				std::cin >> input;
				setPhoneNumber(input);
				std::cout << "Enter your darkest secret: ";
				std::cin >> input;
				setDarkestSecret(input);
		}
		void	printContact() {
			std::cout << firstName << "\n" << lastName << "\n" << nickname << "\n" << phoneNumber << "\n"
				<< darkestSecret << std::endl;
		}
	private:
		std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
		void	setFirstName(const std::string& name) { firstName = name; }
		void	setLastName(const std::string& name) { lastName = name; }
		void	setNickname(const std::string& name) { nickname = name; }
		void	setPhoneNumber(const std::string& number) { isDigitStr(number) ? phoneNumber = number : phoneNumber = "EMPTY"; }
		void	setDarkestSecret(const std::string& secret) { darkestSecret = secret; }
		bool	isDigitStr(const std::string& str) {
			for (std::string::const_iterator i = str.begin(); i != str.end(); i++) {
				if (!isdigit(*i))
					return false;
			}
			return true;
		}
};