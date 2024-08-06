#include "Bureaucrat.hpp"
#include "Colors.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Leo", 149);
        std::cout << b1 << std::endl;
        std::cout << LIGHT_MAGENTA << "decrementing grade" << RESET << std::endl;
        b1.decrementGrade();
        std::cout << b1 << std::endl;
        std::cout << LIGHT_MAGENTA << "decrementing grade" << RESET << std::endl;
        b1.decrementGrade();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b2("Kyle", 2);
        std::cout << b2 << std::endl;
        std::cout << LIGHT_GREEN << "incrementing grade" << RESET << std::endl;
        b2.incrementGrade();
        std::cout << b2 << std::endl;
        std::cout << LIGHT_GREEN << "incrementing grade" << RESET << std::endl;
        b2.incrementGrade();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}