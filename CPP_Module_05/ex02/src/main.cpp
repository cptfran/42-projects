#include"../incl/Bureaucrat.hpp"
#include "../incl/AForm.hpp"
#include "../incl/Colors.hpp"
#include "../incl/ShrubberyCreationForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/PresidentialPardonForm.hpp"

void testShrubbery(Bureaucrat& b1) {
    std::cout << LIGHT_CYAN << "\n********************************" << RESET << std::endl;
    ShrubberyCreationForm shrubbery("home");
    std::cout << shrubbery << std::endl;
    std::cout << b1 << std::endl;
    b1.signForm(shrubbery);
    b1.executeForm(shrubbery);
    std::cout << "\nIncrementing the grade" << std::endl;
    for (int i = b1.getGrade(); i > shrubbery.getGradeToSign(); i--) {
        b1.incrementGrade();
    }
    std::cout << b1 << std::endl;
    b1.signForm(shrubbery);
    b1.executeForm(shrubbery);
    std::cout << "\nIncrementing the grade" << std::endl;
    for (int i = b1.getGrade(); i > shrubbery.getGradeToExecute(); i--) {
        b1.incrementGrade();
    }
    std::cout << b1 << std::endl;
    b1.signForm(shrubbery);
    b1.executeForm(shrubbery);
    std::cout << "\n" << shrubbery;
}

void testRobotomy(Bureaucrat& b1) {
    std::cout << LIGHT_CYAN << "\n********************************" << RESET << std::endl;
    RobotomyRequestForm robotomy("Josh");
    std::cout << robotomy << std::endl;
    std::cout << b1 << std::endl;
    b1.signForm(robotomy);
    b1.executeForm(robotomy);
    std::cout << "\nIncrementing the grade" << std::endl;
    for (int i = b1.getGrade(); i > robotomy.getGradeToSign(); i--) {
        b1.incrementGrade();
    }
    std::cout << b1 << std::endl;
    b1.signForm(robotomy);
    b1.executeForm(robotomy);
    std::cout << "\nIncrementing the grade" << std::endl;
    for (int i = b1.getGrade(); i > robotomy.getGradeToExecute(); i--) {
        b1.incrementGrade();
    }
    std::cout << b1 << std::endl;
    b1.signForm(robotomy);
    b1.executeForm(robotomy);
    std::cout << "\n" << robotomy;
}

void testPresidential(Bureaucrat& b1) {
    std::cout << LIGHT_CYAN << "\n********************************" << RESET << std::endl;
    PresidentialPardonForm presidential("George");
    std::cout << presidential << std::endl;
    std::cout << b1 << std::endl;
    b1.signForm(presidential);
    b1.executeForm(presidential);
    std::cout << "\nIncrementing the grade" << std::endl;
    for (int i = b1.getGrade(); i > presidential.getGradeToSign(); i--) {
        b1.incrementGrade();
    }
    std::cout << b1 << std::endl;
    b1.signForm(presidential);
    b1.executeForm(presidential);
    std::cout << "\nIncrementing the grade" << std::endl;
    for (int i = b1.getGrade(); i > presidential.getGradeToExecute(); i--) {
        b1.incrementGrade();
    }
    std::cout << b1 << std::endl;
    b1.signForm(presidential);
    b1.executeForm(presidential);
    std::cout << "\n" << presidential;
}

int main() {
    Bureaucrat b1;
    try {
        b1 = Bureaucrat("default", 146);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    testShrubbery(b1);
    testRobotomy(b1);
    testPresidential(b1);
    return 0;
}