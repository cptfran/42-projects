#include "../incl/AForm.hpp"
#include "../incl/Colors.hpp"

AForm::AForm() : name("default"), isSigned(false), gradeToSign(70), gradeToExecute(25), target("none") {}

AForm::AForm(const std::string& name, const int& gradeToSign, const int& gradeToExecute, const std::string& target)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), target(target) {}

AForm::AForm(const AForm& obj) : name(obj.name), isSigned(obj.isSigned), gradeToSign(obj.gradeToSign),
                                 gradeToExecute(obj.gradeToExecute) {}

AForm& AForm::operator=(const AForm& obj) {
    if (this != &obj) {
        this->isSigned = obj.isSigned;
    }
    return *this;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return RED "Grade too high" RESET;
}

const char* AForm::GradeTooLowException::what() const throw() {
    return RED "Grade too low" RESET;
}

const char* AForm::FormNotSignedException::what() const throw() {
    return RED "Form is not signed" RESET;
}

AForm::~AForm() {}

const std::string& AForm::getName() const {
    return this->name;
}

bool AForm::getIsSigned() const {
    return this->isSigned;
}

const int& AForm::getGradeToSign() const {
    return this->gradeToSign;
}

const int& AForm::getGradeToExecute() const {
    return this->gradeToExecute;
}

const std::string& AForm::getTarget() const {
    return this->target;
}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {
    os << "Form name: " << PURPLE << obj.getName() << RESET << "\nSigned: " << PURPLE
        <<  (obj.getIsSigned() ? "yes" : "no") << RESET << "\nGrade to sign: " << PURPLE << obj.getGradeToSign()
        << RESET << "\nGrade to execute: " << PURPLE << obj.getGradeToExecute() << RESET << "\nTarget: " << PURPLE
        << obj.getTarget() << RESET << std::endl;
    return os;
}

void AForm::beSigned(const Bureaucrat& obj) {
    std::cout << LIGHT_YELLOW "Signing..." RESET << std::endl;
    if (obj.getGrade() <= this->gradeToSign) {
        this->isSigned = true;
    } else {
        throw GradeTooLowException();
    }
}

void AForm::execute(const Bureaucrat &executor) const {
    std::cout << LIGHT_YELLOW "Executing..." << std::endl;
    if (!this->isSigned) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > this->gradeToExecute) {
        throw GradeTooLowException();
    }
    this->executeAction();
}