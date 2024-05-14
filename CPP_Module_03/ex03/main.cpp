#include "Msg.hpp"
#include "DiamondTrap.hpp"
#include <cstdlib>
#include <ctime>

    void displayCharStat(DiamondTrap& obj) {
    std::cout << "\n🤖 🤖 🤖 " << BROWN << obj.getName() << " 🤖 🤖 🤖" << std::endl;
    std::cout << LIGHT_GREEN << "\n❤️  (" << obj.getHitPoints() << ")\n";
    std::cout << BLUE << "\n⚡️ (" << obj.getEnergyPoints() << ")\n";
    std::cout << LIGHT_RED << "\n⚔️  (" << obj.getAttackDamage() << ")\n" << RESET << std::endl;
}

int action(DiamondTrap& actionTaker, DiamondTrap& actionReceiver, std::string& input) {
    std::cout << MSG_CHOOSE << YELLOW <<"\n" << actionTaker.getName() << ": ";
    std::getline(std::cin, input);
    if (input == "exit") {
        std::cout << MSG_EXIT << std::endl;
        return 0;
    } else if (input == "attack") {
        if (actionTaker.getEnergyPoints() > 0) {
            actionTaker.attack(actionReceiver.getName());
            actionReceiver.takeDamage(actionTaker.getAttackDamage());
        } else {
            actionTaker.attack(actionReceiver.getName());
        }
        if (actionReceiver.getHitPoints() == 0) {
            std::cout << LIGHT_CYAN << "\n🥇🥇🥇 " << actionTaker.getName() << " Won 🥇🥇🥇\n\n"
            << MSG_GAME_OVER << std::endl;
            return 0;
        } else {
            return 1;
        }
    } else if (input == "repair") {
        const int randomHeal = std::rand() % 40 + 1;
        actionTaker.beRepaired(randomHeal);
        return 1;
    } else if (input == "highfive") {
        actionTaker.highFivesGuys();
        return 1;
    } else if (input == "guard") {
        actionTaker.guardGate();
        return 1;
    } else if (input == "whoami") {
        actionTaker.whoAmI();
        return 1;
    } else {
        std::cerr << ERR_INPUT << std::endl;
        return -1;
    }
}

int main() {
    std::cout << MSG_START << std::endl;
    std::srand(std::time(0));
    DiamondTrap fighter1("Elon");
    DiamondTrap fighter2("Mark");
    std::string input;
    displayCharStat(fighter1);
    displayCharStat(fighter2);
    while (true) {
        while (true) {
            const int actionVal = action(fighter1, fighter2, input);
            if (actionVal == -1) {
                continue;
            } else if (actionVal == 0) {
                return 0;
            } else {
                displayCharStat(fighter1);
                displayCharStat(fighter2);
                break;
            }
        }
        while (true) {
            const int actionVal = action(fighter2, fighter1, input);
            if (actionVal == -1) {
                continue;
            } else if (actionVal == 0) {
                return 0;
            } else {
                displayCharStat(fighter1);
                displayCharStat(fighter2);
                break;
            }
        }
    }
}
