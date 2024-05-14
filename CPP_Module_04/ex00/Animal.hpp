#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <string>

class Animal {
public:
    Animal();
    Animal(const Animal& obj);
    Animal& operator=(const Animal& obj);
    virtual ~Animal();
    virtual void makeSound();
protected:
    std::string type;
};

#endif // ANIMAL_HPP
