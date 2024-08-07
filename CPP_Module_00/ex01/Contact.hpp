#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
public:
	void setContact();
	void printStartContactInfo(int i);
	void printAllContactInfo();

private:
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;
	void setFirstName(const std::string& name);
	void setLastName(const std::string& name);
	void setNickname(const std::string& name);
	void setPhoneNumber(std::string& number);
	void setDarkestSecret(const std::string& secret);
	bool isDigitStr(const std::string& str);
	std::string truncateString(std::string str);
	bool isCorrectField(std::string& input, std::string input_msg);
};

#endif // CONTACT_HPP