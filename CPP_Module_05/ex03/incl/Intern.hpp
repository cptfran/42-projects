#ifndef INTERN_HPP
#define INTERN_HPP
#include "../incl/AForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern& toCopy);
    Intern& operator=(const Intern& toCopy);
    ~Intern();
    AForm* makeForm(const std::string& formName, const std::string& formTarget);
    class FormNotFoundException : public std::exception {
        const char* what() const throw();
    };
private:
    static AForm* makeShrubberyForm(const std::string& target       );
    static AForm* makeRobotomyForm(const std::string& target);
    static AForm* makePresidentialForm(const std::string& target);
};

#endif