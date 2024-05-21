#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& form);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& form);
    ~ShrubberyCreationForm();
    void createShrubberyFile();
};

#endif