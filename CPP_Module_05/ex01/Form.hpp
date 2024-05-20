#include <string>

class Form {
public:
    Form();
    Form(const Form& obj);
    Form& operator=(const Form& obj);
    ~Form();
    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;
};