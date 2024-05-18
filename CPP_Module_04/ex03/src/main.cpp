#include <iostream>
#include <sstream>
#include "../incl/Msg.hpp"
#include "../incl/MateriaSource.hpp"
#include "../incl/Character.hpp"
#include "../incl/Ice.hpp"
#include "../incl/Cure.hpp"

std::string* charInv[4];
std::string* matInv[4];

void add_info(std::string* inv, std::string& mat) {
    static int oldest = 0;
    for (int i = 0; i < 4; i++) {
        if (inv[i].empty()) {
            inv[i] = mat;
            oldest = i;
            return;
        }
    }
    inv[oldest] = mat;
    if (oldest == 3) {
        oldest = 0;
    } else {
        ++oldest;
    }
}

void handleLearnMateria(IMateriaSource* materiaSource, std::string& input) {
    while (true) {
        std::cout << MSG_CHOOSE_MATERIA << std::endl;
        std::getline(std::cin, input);
        if (input == "ice") {
            materiaSource->learnMateria(new Ice());

            return;
        } else if (input == "cure") {
            materiaSource->learnMateria(new Cure());
            return;
        } else {
            std::cout << ERR_WRONG_CMD << std::endl;
            continue;
        }
    }
}

AMateria* handleCreateMateria(IMateriaSource* materiaSource, std::string& input) {
    std::cout << MSG_CHOOSE_MATERIA << std::endl;
    std::getline(std::cin, input);
    return materiaSource->createMateria(input);
}

void handleUnequip(ICharacter* me) {
    std::string input;
    while (true) {
        std::cout << MSG_CHOOSE_INDEX << std::endl;
        std::getline(std::cin, input);
        std::istringstream iss(input);
        int idx;
        if (!(iss >> idx)) {
            std::cerr << RED << "Error: it's not a number: " << input << RESET << std::endl;
            continue;
        } else {
            me->unequip(idx);
            return;
        }
    }
}

void handleUse(ICharacter* me, ICharacter* target1, ICharacter* target2) {
    std::string input;
    while (true) {
        std::cout << MSG_CHOOSE_TARGET << std::endl;
        std::getline(std::cin, input);
        if (input == "target1") {
            std::cout << MSG_CHOOSE_INDEX << std::endl;
            std::getline(std::cin, input);
            std::istringstream iss(input);
            int idx;
            if (!(iss >> idx)) {
                std::cerr << RED << "Error: it's not a number: " << input << RESET << std::endl;
                continue;
            } else {
                std::cout << MSG_CHOOSE_TARGET << std::endl;
                me->use(idx, *target1);
                return;
            }
        } else if (input == "target2") {
            std::cout << MSG_CHOOSE_INDEX << std::endl;
            std::getline(std::cin, input);
            std::istringstream iss(input);
            int idx;
            if (!(iss >> idx)) {
                std::cerr << RED << "Error: it's not a number: " << input << RESET << std::endl;
                continue;
            } else {
                std::cout << MSG_CHOOSE_TARGET << std::endl;
                me->use(idx, *target2);
                return;
            }
        } else {
            std::cerr << ERR_WRONG_CMD << std::endl;
            continue;
        }
    }
}

int main() {
    IMateriaSource* materiaSource = new MateriaSource();
    AMateria* materia = NULL;
    ICharacter* me = new Character("me");
    ICharacter* target1 = new Character("target1");
    ICharacter* target2 = new Character("target2");
    std::string input;
    while (true) {
        std::cout << MSG_CHOOSE_ACTION << std::endl;
        std::getline(std::cin, input);
        if (input == "exit") {
            delete materiaSource;
            delete me;
            delete target1;
            delete target2;
            return 0;
        } else if (input == "learnMateria") {
            handleLearnMateria(materiaSource, input);
        } else if (input == "createMateria") {
            materia = handleCreateMateria(materiaSource, input);
        } else if (input == "equip") {
            me->equip(materia);
        } else if (input == "unequip") {
            handleUnequip(me);
        } else if (input == "use") {
            handleUse(me, target1, target2);
        } else {
            std::cerr << ERR_WRONG_CMD << std::endl;
            continue;
        }
    }
}