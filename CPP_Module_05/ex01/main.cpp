#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Colors.hpp"

int main() {

    std::cout << LIGHT_CYAN << "\n********************************" << RESET << std::endl;
    AForm f1("GD3", 67, 20);
    std::cout << f1 << std::endl;
    Bureaucrat b1;
    try {
        b1 = Bureaucrat("default", 120);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << b1 << std::endl;
    try {
        f1.beSigned(b1);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    b1.signForm(f1);

    std::cout << LIGHT_CYAN << "\n********************************" << RESET << std::endl;
    std::cout << f1 << std::endl;
    try {
        b1 = Bureaucrat("default", 60);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << b1 << std::endl;
    try {
        f1.beSigned(b1);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    b1.signForm(f1);

    return 0;
}