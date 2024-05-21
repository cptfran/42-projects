#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& form);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& form);
    ~PresidentialPardonForm();
    void executeAction() const;
private:
    void pardon() const;
};

#endif