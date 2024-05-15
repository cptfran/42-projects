#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Msg.hpp"
#include <iostream>

int main() {

//    SHALLOW/DEEP COPY TEST (DOG)
    std::cout << MSG_SHALLOW_DEEP_TEST_DOG << std::endl;
    Dog* rex = new Dog;
    std::string* rexIdeas = rex->getBrainIdeas();
    std::cout << YELLOW << "rex ideas:" << RESET << std::endl;
    for (int i = 0; !rexIdeas[i].empty(); i++) {
        std::cout << CYAN << rexIdeas[i] << RESET << std::endl;
    }
    Dog *tmp = new Dog(*rex);
    std::cout << YELLOW << "tmp ideas:" << RESET << std::endl;
    std::string* tmpIdeas = tmp->getBrainIdeas();
    for (int i = 0; !tmpIdeas[i].empty(); i++) {
        std::cout << CYAN << tmpIdeas[i] << RESET << std::endl;
    }
    delete tmp;
    rexIdeas = rex->getBrainIdeas();
    std::cout << YELLOW << "rex ideas:" << RESET << std::endl;
    for (int i = 0; !rexIdeas[i].empty(); i++) {
        std::cout << CYAN << rexIdeas[i] << RESET << std::endl;
    }
    delete rex;

//    SHALLOW/DEEP COPY TEST (CAT)
    std::cout << MSG_SHALLOW_DEEP_TEST_CAT << std::endl;
    Cat* garfield = new Cat;
    std::string* garfieldIdeas = garfield->getBrainIdeas();
    std::cout << YELLOW << "garfield ideas:" << RESET << std::endl;
    for (int i = 0; !garfieldIdeas[i].empty(); i++) {
        std::cout << CYAN << garfieldIdeas[i] << RESET << std::endl;
    }
    Cat *tmp2 = new Cat(*garfield);
    std::cout << YELLOW << "tmp2 ideas:" << RESET << std::endl;
    std::string* tmp2Ideas = tmp2->getBrainIdeas();
    for (int i = 0; !tmp2Ideas[i].empty(); i++) {
        std::cout << CYAN << tmp2Ideas[i] << RESET << std::endl;
    }
    delete tmp2;
    garfieldIdeas = garfield->getBrainIdeas();
    std::cout << YELLOW << "garfield ideas:" << RESET << std::endl;
    for (int i = 0; !garfieldIdeas[i].empty(); i++) {
        std::cout << CYAN << garfieldIdeas[i] << RESET << std::endl;
    }
    delete garfield;

//    ARRAY OF ANIMALS TEST
    std::cout << MSG_ARRAY_OF_ANIMALS_TEST << std::endl;
    Animal* herd[10];
    int i;
    for (i = 0; i < 10; i++) {
        if (i < 5) {
            herd[i] = new Dog;
        } else {
            herd[i] = new Cat;
        }
    }
    for (i = 0; i < 10; i++) {
        delete herd[i];
    }
    return 0;
}