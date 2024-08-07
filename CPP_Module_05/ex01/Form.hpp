#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
public:
    AForm();
    AForm(const std::string& name, const int& gradeToSign, const int& gradeToExecute);
    AForm(const AForm& obj);
    AForm& operator=(const AForm& obj);
    ~AForm();
    class GradeTooHighException : public std::exception
    {
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
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

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif