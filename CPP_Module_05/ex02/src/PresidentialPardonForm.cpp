#include "../incl/PresidentialPardonForm.hpp"
#include "../incl/Colors.hpp"

PresidentialPardonForm::PresidentialPardonForm()
        : AForm("PresidentialPardonForm", 25, 5, "none") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
        : AForm("PresidentialPardonForm", 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form) : AForm(form) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &form) {
    if (this != &form) {
        AForm::operator=(form);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::pardon() {
    std::cout << PURPLE << this->getTarget() << LIGHT_YELLOW " has been pardoned by Zaphod Beeblebrox" RESET
        << std::endl;
}