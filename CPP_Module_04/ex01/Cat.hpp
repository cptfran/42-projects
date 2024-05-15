#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
    Cat();
    Cat(const Cat& obj);
    Cat& operator=(const Cat& obj);
    ~Cat();
    void makeSound() const;
    void setBrainIdeas(const std::string* newIdeas, int size);
    std::string* getBrainIdeas();
private:
    Brain* brain;
};

#endif