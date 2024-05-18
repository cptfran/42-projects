#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP
#include <string>

class WrongAnimal {
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal& obj);
    WrongAnimal& operator=(const WrongAnimal& obj);
    ~WrongAnimal();
    void makeSound() const;
    const std::string& getType() const;
protected:
    std::string type;
};

#endif // WRONGANIMAL_HPP
