#include "../incl/Intern.hpp"
#include "../incl/ShrubberyCreationForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/PresidentialPardonForm.hpp"
#include "../incl/Colors.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& toCopy)
{
    *this = toCopy;
}

Intern& Intern::operator=(const Intern& toCopy)
{
    if (this != &toCopy)
    {
        *this = toCopy;
    }
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeShrubberyForm(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyForm(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialForm(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

const char* Intern::FormNotFoundException::what() const throw()
{
    return RED "Form not found" RESET;
}


AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget)
{
    typedef AForm*(*formFunc)(const std::string& target);
    const formFunc funcArr[] = {Intern::makeShrubberyForm, Intern::makeRobotomyForm, Intern::makePresidentialForm};
    std::string names[] = {"shrubbery request", "robotomy request", "presidential request"};
    for (int i = 0; i < 3; i++)
    {
        if (formName == names[i])
        {
            return funcArr[i](formTarget);
        }
    }
    throw FormNotFoundException();
}
