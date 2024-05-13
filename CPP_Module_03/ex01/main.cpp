#include "msg.hpp"
#include "ScavTrap.hpp"
#include <iomanip>

void displayCharsStat(ScavTrap& obj1, ScavTrap& obj2) {
    std::cout << std::setw(30) << std::setfill('.') << std::left << LIGHT_PURPLE << obj1.getName();
    std::cout << std::setw(30) << std::setfill('.') << std::left << obj2.getName() << RESET << std::endl;
    std::cout << std::setw(30) << std::setfill('.') << std::left << LIGHT_CYAN << "Hit points" << LIGHT_BLUE
     << obj1.getHitPoints();
    std::cout << std::setw(30) << std::setfill('.') << std::left << LIGHT_CYAN << "Hit points" << LIGHT_BLUE
     << obj2.getHitPoints() << std::endl;
}

int main() {
    std::cout << MSG_START << std::endl;
    ScavTrap figther1("Mark");
    ScavTrap figther2("Elon");
    displayCharsStat(figther1, figther2);
    return 0;
    std::string input;
    while (true) {
        std::cout << MSG_CHOOSE << std::endl;
        std::getline(std::cin, input);
        if (input != "exit" || input != "attack" || input != "repair" || input != "guard") {
            std::cerr << ERR_INPUT << std::endl;
            continue;
        }
    }
    return 0;
}
