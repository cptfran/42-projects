#include "../incl/AForm.hpp"
#include "../incl/Intern.hpp"

int main() {
    try {
        Intern someRandomIntern;
        const AForm* f1 = someRandomIntern.makeForm("shrubbery request", "Bender");
        std::cout << *f1 << std::endl;
        delete f1;
        const AForm* f2 = someRandomIntern.makeForm("robotomy request", "Bender");
        std::cout << *f2 << std::endl;
        delete f2;
        const AForm* f3 = someRandomIntern.makeForm("presidential request", "Bender");
        std::cout << *f3 << std::endl;
        delete f3;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}