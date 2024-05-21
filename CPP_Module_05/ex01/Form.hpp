#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Form {
public:
    Form();
    Form(const std::string& name, const int& gradeToSign, const int& gradeToExecute);
    Form(const Form& obj);
    Form& operator=(const Form& obj);
    ~Form();
    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };
    const std::string& getName() const;
    bool getIsSigned() const;
    const int& getGradeToSign() const;
    const int& getGradeToExecute() const;
    void beSigned(const Bureaucrat& obj);
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif