#include "Form.hpp"
#include "Colors.hpp"

Form::Form() : name("default"), isSigned(false), gradeToSign(70), gradeToExecute(25) {}

Form::Form(const std::string& name, const int& gradeToSign, const int& gradeToExecute) : name(name),
    isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {}

Form::Form(const Form& obj) : name(obj.name), isSigned(obj.isSigned), gradeToSign(obj.gradeToSign),
    gradeToExecute(obj.gradeToExecute) {}

Form& Form::operator=(const Form& obj) {
    if (this != &obj) {
        this->isSigned = obj.isSigned;
    }
    return *this;
}

const char* Form::GradeTooHighException::what() const throw() {
    return RED "Grade too high" RESET;
}

const char* Form::GradeTooLowException::what() const throw() {
    return RED "Grade too low" RESET;
}

Form::~Form() {}

const std::string& Form::getName() const {
    return this->name;
}

bool Form::getIsSigned() const {
    return this->isSigned;
}

const int& Form::getGradeToSign() const {
    return this->gradeToSign;
}

const int& Form::getGradeToExecute() const {
    return this->gradeToExecute;
}


std::ostream& operator<<(std::ostream& os, const Form& obj) {
    std::string yesNo;
    if (obj.getIsSigned()) {
        yesNo = LIGHT_GREEN "Yes" RESET;
    } else {
        yesNo = RED "No" RESET;
    }
    os << "Form name: " << YELLOW << obj.getName() << RESET << "\nSigned: " << yesNo << " \nGrade to sign: " << YELLOW
        << obj.getGradeToSign() << RESET << "\nGrade to execute: " << YELLOW << obj.getGradeToExecute() << RESET
        << std::endl;
    return os;
}

void Form::beSigned(const Bureaucrat& obj) {
    if (obj.getGrade() <= this->gradeToSign) {
        this->isSigned = true;
    } else {
        throw GradeTooLowException();
    }
}
