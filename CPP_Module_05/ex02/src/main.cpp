#include"../incl/Bureaucrat.hpp"
#include "../incl/AForm.hpp"
#include "../incl/Colors.hpp"
#include "../incl/ShrubberyCreationForm.hpp"
#include "../incl/RobotomyRequestForm.hpp"
#include "../incl/PresidentialPardonForm.hpp"

int main() {

    std::cout << LIGHT_CYAN << "\n********************************" << RESET << std::endl;
    ShrubberyCreationForm shrubbery("home");
    std::cout << shrubbery << std::endl;
    shrubbery.createShrubberyFile();

    std::cout << LIGHT_CYAN << "\n********************************" << RESET << std::endl;
    RobotomyRequestForm robotomy("Josh");
    std::cout << robotomy << std::endl;
    robotomy.makeNoise();
    robotomy.robotomize();

    std::cout << LIGHT_CYAN << "\n********************************" << RESET << std::endl;
    PresidentialPardonForm presidential("Ludwik");
    std::cout << presidential << std::endl;
    presidential.pardon();
    return 0;
}