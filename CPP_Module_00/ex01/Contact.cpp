#include "Contact.hpp"
#include "colors.h"
#include <iomanip>

void Contact::setContact()
{
    std::cout << std::endl;
    std::string input;
    while (!isCorrectField(input, "Enter first name"))
    {
        continue;
    }
    setFirstName(input);
    while (!isCorrectField(input, "Enter last name"))
    {
        continue;
    }
    setLastName(input);
    while (!isCorrectField(input, "Enter nickname"))
    {
        continue;
    }
    setNickname(input);
    while (!isCorrectField(input, "Enter phone number"))
    {
        continue;
    }
    setPhoneNumber(input);
    while (!isCorrectField(input, "Enter your darkest secret"))
    {
        continue;
    }
    setDarkestSecret(input);
}

void Contact::printStartContactInfo(const int i)
{
    std::cout << std::setw(10) << std::right << std::setfill(' ') << i << GRAY << '|' << RESET
              << std::setw(10) << std::right << std::setfill(' ') << truncateString(firstName) << GRAY << '|' << RESET
              << std::setw(10) << std::right << std::setfill(' ') << truncateString(lastName) << GRAY << '|' << RESET
              << std::setw(10) << std::right << std::setfill(' ') << truncateString(nickname) << RESET << std::endl;
}

void Contact::printAllContactInfo()
{
    std::cout << "\n" << GRAY << "FIRST NAME: " << RESET << firstName << "\n" << GRAY << "LAST NAME: "
              << RESET << lastName << "\n" << GRAY << "NICKNAME: " << RESET << nickname << "\n" << GRAY
              << "PHONE NUMBER: " << RESET << phoneNumber << "\n" << GRAY << "DARKEST SECRET: " << RESET
              << darkestSecret << "\n" << std::endl;
}

void Contact::setFirstName(const std::string& name)
{
    firstName = name;
}

void Contact::setLastName(const std::string& name)
{
    lastName = name;
}

void Contact::setNickname(const std::string& name)
{
    nickname = name;
}

void Contact::setPhoneNumber(std::string& number)
{
    while (!isDigitStr(number))
    {
        std::cout << RED << "\nUSE ONLY DIGITS\n" << RESET << std::endl;
        std::cout << GRAY << "Enter phone number: " << RESET;
        std::getline(std::cin, number);
    }
    phoneNumber = number;
}

void Contact::setDarkestSecret(const std::string& secret)
{
    darkestSecret = secret;
}

bool Contact::isDigitStr(const std::string& str)
{
    for (std::string::const_iterator i = str.begin(); i != str.end(); i++)
    {
        if (!isdigit(*i))
        {
            return false;
        }
    }
    return true;
}

std::string Contact::truncateString(std::string str)
{
    if (str.length() >= 10)
    {
        return str.substr(0, 9) + ".";
    }
    return str;
}

bool Contact::isCorrectField(std::string& input, std::string input_msg)
{
    std::cout << GRAY << input_msg << ": " << RESET;
    std::getline(std::cin, input);
    if (input.find(' ') != std::string::npos)
    {
        std::cout << RED << "\nSPACES NOT ALLOWED\n" << RESET << std::endl;
        return false;
    }
    if (input.empty())
    {
        std::cout << RED << "\nFIELD CANNOT BE EMPTY\n" << RESET << std::endl;
        return false;
    }
    return true;
}