#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* k = new WrongAnimal();
    const WrongAnimal* l = new WrongCat();
    const WrongCat* o = new WrongCat();
    std::cout << meta->getType() << " ";
    meta->makeSound();
    std::cout << j->getType() << " ";
    j->makeSound();
    std::cout << i->getType() << " ";
    i->makeSound();
    std::cout << k->getType() << " ";
    k->makeSound();
    std::cout << l->getType() << " ";
    l->makeSound();
    std::cout << o->getType() << " ";
    o->makeSound();
    delete meta;
    delete j;
    delete i;
    delete k;
    delete l;
    delete o;
    return 0;
}