#include "AMateria.hpp"

class Ice : public AMateria {
    Ice();
    Ice(const std::string& type);
    Ice(const Ice& obj);
    Ice& operator=(const Ice& obj);
    ~Ice();
    
};