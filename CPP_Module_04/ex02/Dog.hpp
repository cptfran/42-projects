#ifndef DOG_HPP
#define DOG_HPP
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
public:
    Dog();
    Dog(const Dog& obj);
    Dog& operator=(const Dog& obj);
    ~Dog();
    void makeSound() const;
    void setBrainIdeas(const std::string* newIdeas, int size);
    std::string* getBrainIdeas();
private:
    Brain* brain;
};

#endif