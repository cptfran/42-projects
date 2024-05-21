#include "Bureaucrat.hpp"
#include "Colors.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("Joe"), grade(80) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) {
    if (grade > 150) {
        throw GradeTooLowException();
    } else if (grade < 1) {
        throw GradeTooHighException();
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name(obj.name), grade(obj.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) {
    if (this != &obj) {
        this->grade = obj.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return RED "Grade too high" RESET;
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return RED "Grade too low" RESET;
}

const std::string& Bureaucrat::getName() const {
    return this->name;
}

int Bureaucrat::getGrade() const {
    return this->grade;
}

void Bureaucrat::incrementGrade() {
    if (this->grade - 1 < 1) {
        throw GradeTooHighException();
    }
    this->grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->grade + 1 > 150) {
        throw GradeTooLowException();
    }
    this->grade++;
}

void Bureaucrat::signForm(AForm& obj) const {
    try {
        obj.beSigned(*this);
        std::cout << YELLOW << this->name << LIGHT_GREEN << " signed " << PURPLE << obj.getName() << RESET << std::endl;
    } catch (std::exception& e) {
        std::cerr << YELLOW << this->name << RED << " couldn't sign " << PURPLE << obj.getName() << RESET
                  << RED << " because " << e.what() << RESET << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
    os << YELLOW << obj.getName() << RESET << ", bureaucrat grade " << CYAN <<  obj.getGrade() << RESET;
    return os;
}
