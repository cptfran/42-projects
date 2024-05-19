#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <string>

class Bureaucrat {
public:
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    ~Bureaucrat();
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };
    class GrateTooLowException : public std::exception {
        const char* what() const throw();
    };
private:
    const std::string name;
    int grade;
};

#endif