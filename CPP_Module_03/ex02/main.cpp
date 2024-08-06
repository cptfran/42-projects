#include "Msg.hpp"
#include "FragTrap.hpp"
#include <iomanip>
#include <cstdlib>
#include <ctime>

void displayCharStat(FragTrap& obj)
{
    std::cout << "\n🤖 🤖 🤖 " << BROWN << obj.getName() << " 🤖 🤖 🤖" << std::endl;
    std::cout << LIGHT_GREEN << "\n❤️  (" << obj.getHitPoints() << ")\n";
    std::cout << BLUE << "\n⚡️ (" << obj.getEnergyPoints() << ")\n";
    std::cout << LIGHT_RED << "\n⚔️  (" << obj.getAttackDamage() << ")\n" << RESET << std::endl;
}

int action(FragTrap& actionTaker, FragTrap& actionReceiver, std::string& input)
{
    std::cout << MSG_CHOOSE << YELLOW <<"\n" << actionTaker.getName() << ": ";
    std::getline(std::cin, input);
    if (input == "exit")
    {
        std::cout << MSG_EXIT << std::endl;
        return 0;
    }
    if (input == "attack")
    {
        if (actionTaker.getEnergyPoints() > 0)
        {
            actionTaker.attack(actionReceiver.getName());
            actionReceiver.takeDamage(actionTaker.getAttackDamage());
        }
        else
        {
            actionTaker.attack(actionReceiver.getName());
        }
        if (actionReceiver.getHitPoints() == 0)
        {
            std::cout << LIGHT_CYAN << "\n🥇🥇🥇 " << actionTaker.getName() << " Won 🥇🥇🥇\n\n"
            << MSG_GAME_OVER << std::endl;
            return 0;
        }
        return 1;
    }
    if (input == "repair")
    {
        const int randomHeal = std::rand() % 40 + 1;
        actionTaker.beRepaired(randomHeal);
        return 1;
    }
    if (input == "highfive")
    {
        actionTaker.highFivesGuys();
        return 1;
    }
    std::cerr << ERR_INPUT << std::endl;
    return -1;
}

int main()
{
    std::cout << MSG_START << std::endl;
    std::srand(std::time(0));
    FragTrap fighter1("Elon");
    FragTrap fighter2("Mark");
    std::string input;
    displayCharStat(fighter1);
    displayCharStat(fighter2);
    while (true)
    {
        while (true)
        {
            const int actionVal = action(fighter1, fighter2, input);
            if (actionVal == -1)
            {
                continue;
            }
            if (actionVal == 0)
            {
                return 0;
            }
            displayCharStat(fighter1);
            displayCharStat(fighter2);
            break;
        }
        while (true)
        {
            const int actionVal = action(fighter2, fighter1, input);
            if (actionVal == -1)
            {
                continue;
            }
            if (actionVal == 0)
            {
                return 0;
            }
            displayCharStat(fighter1);
            displayCharStat(fighter2);
            break;
        }
    }
}
