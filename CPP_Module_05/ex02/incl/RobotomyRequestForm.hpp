#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& form);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& form);
    ~RobotomyRequestForm();
    void makeNoise();
    void robotomize();
};

#endif