#include <string>

class Contact {
	public:
		void	setContact(const std::string& f_name, const std::string& l_name, const std::string& n_name,
			const std::string& p_number, const std::string& d_secret) {
				setFirstName(f_name);
				setLastName(l_name);
				setNickname(n_name);
				setPhoneNumber(p_number);
				setDarkestSecret(d_secret);
		}
	private:
		std::string first_name;
		std::string	last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
		void	setFirstName(const std::string& name) { first_name = name; }
		void	setLastName(const std::string& name) { last_name = name; }
		void	setNickname(const std::string& name) { nickname = name; }
		void	setPhoneNumber(const std::string& number) {
			if (isDigitStr(number))
				phone_number = number;
			else
				phone_number = "EMPTY";
		}
		void	setDarkestSecret(const std::string& secret) { darkest_secret = secret; }
		bool	isDigitStr(const std::string& str) {
			for (std::string::const_iterator i = str.begin(); i != str.end(); i++) {
				if (!isdigit(*i))
					return false;
			}
			return true;
		}
};