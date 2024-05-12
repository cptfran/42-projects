#include "msg.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << MSG_START << std::endl;
    ScavTrap fighter1("Mark");
    ScavTrap figther2("Elon");
    std::string input;
    while (true) {
        std::cout << MSG_CHOOSE << std::endl;
        std::getline(std::cin, input);
    }
}
