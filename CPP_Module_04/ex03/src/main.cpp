#include <iostream>
#include <sstream>
#include <iomanip>
#include "../incl/Msg.hpp"
#include "../incl/MateriaSource.hpp"
#include "../incl/Character.hpp"
#include "../incl/Ice.hpp"
#include "../incl/Cure.hpp"

std::string charInv[4];
std::string matInv[4];

void printInfo(const std::string& mat) {
    std::cout << CYAN << std::setfill('*') << std::setw(53) << "*" << std::endl;
    std::cout << "|" << std::setw(20) << std::setfill(' ') << std::right << "Character slots |";
    for (int i = 0; i < 4; i++) {
        std::cout << std::setw(6) << std::setfill(' ') << std::right << charInv[i] << " |";
    }
    std::cout << std::endl;
    std::cout << std::setfill('*') << std::setw(53) << "*" << std::endl;
    std::cout << "|" << std::setw(20) << std::setfill(' ') << std::right << "MateriaSrc slots |";
    for (int i = 0; i < 4; i++) {
        std::cout << std::setw(6) << std::setfill(' ') << std::right << matInv[i] << " |";
    }
    std::cout << std::endl;
    std::cout << std::setfill('*') << std::setw(53) << "*" << std::endl;
    std::cout << "|" << std::setw(20) << std::setfill(' ') << std::right << "Current materia |";
    std::cout << std::setw(30) << std::setfill(' ') << std::right << mat << " |";
    std::cout << std::endl;
    std::cout << std::setfill('*') << std::setw(53) << "*" << RESET << std::endl;
}

void addInfo(std::string inv[], const std::string& mat) {
    static int oldest = -1;
    for (int i = 0; i < 4; i++) {
        if (inv[i].empty()) {
            inv[i] = mat;
            if (oldest == -1) {
                oldest = i;
            }
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

void removeInfoChar(int idx) {
    if (idx >= 0 && idx < 4) {
        matInv[idx] = "";
    }
}

void handleLearnMateria(IMateriaSource* materiaSource, std::string& input) {
    while (true) {
        std::cout << MSG_CHOOSE_MATERIA << std::endl;
        std::getline(std::cin, input);
        if (input == "ice") {
            materiaSource->learnMateria(new Ice());
            addInfo(matInv, input);
            return;
        } else if (input == "cure") {
            materiaSource->learnMateria(new Cure());
            addInfo(matInv, input);
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
            removeInfoChar(idx);
            return;
        }
    }
}

void handleUse(ICharacter* me, ICharacter* target1, ICharacter* target2) {
    std::string input;
    std::string input2;
    while (true) {
        std::cout << MSG_CHOOSE_TARGET << std::endl;
        std::getline(std::cin, input);
        if (input == "target1" || input == "target2") {
            std::cout << MSG_CHOOSE_INDEX << std::endl;
            std::getline(std::cin, input2);
            std::istringstream iss(input2);
            int idx;
            if (!(iss >> idx)) {
                std::cerr << RED << "Error: it's not a number: " << input << RESET << std::endl;
                continue;
            } else {
                std::cout << MSG_CHOOSE_TARGET << std::endl;
                if (input == "target1") {
                    me->use(idx, *target1);
                } else {
                    me->use(idx, *target2);
                }
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
            if (materia != NULL) {
                addInfo(charInv, materia->getType());
            }
        } else if (input == "unequip") {
            handleUnequip(me);
        } else if (input == "use") {
            handleUse(me, target1, target2);
        } else if (input == "info") {
            if (materia == NULL) {
                printInfo("");
            } else {
                printInfo(materia->getType());
            }
        } else {
            std::cerr << ERR_WRONG_CMD << std::endl;
            continue;
        }
    }
}