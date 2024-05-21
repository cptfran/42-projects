#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/Colors.hpp"
#include "../incl/Emoji.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
        : AForm("RobotomyRequestForm", 72, 45, "none") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
        : AForm("RobotomyRequestForm", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form) : AForm(form) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &form) {
    if (this != &form) {
        AForm::operator=(form);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::makeNoise() {
    std::cout << LIGHT_MAGENTA << NOISE " Drilling noises " NOISE << RESET
        << std::endl;
}

void RobotomyRequestForm::robotomize() {
    srand(time(0));
    int random = rand() % 2;
    if (random == 1) {
        std::cout << PURPLE << this->getTarget() << LIGHT_CYAN << " has been robotimized" << RESET << std::endl;
    } else {
        std::cout << PURPLE << this->getTarget() << LIGHT_RED << ": robotomy failed" << RESET << std::endl;
    }
}