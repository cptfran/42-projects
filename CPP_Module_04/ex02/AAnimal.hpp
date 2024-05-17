#ifndef AANIMAL_HPP
#define AANIMAL_HPP
#include <string>

class AAnimal {
public:
    AAnimal();
    AAnimal(const AAnimal& obj);
    AAnimal& operator=(const AAnimal& obj);
    virtual ~AAnimal();
    virtual void makeSound() const = 0;
    const std::string& getType() const;
protected:
    std::string type;
};

#endif // AANIMAL_HPP
