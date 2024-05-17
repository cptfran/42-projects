#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
public:
    MateriaSource();
    MateriaSource(const MateriaSource& obj);
    MateriaSource& operator=(const MateriaSource& obj);
    ~MateriaSource();
    void learnMateria(AMateria* m);
    AMateria* createMateria(const std::string& type);
private:
    AMateria* slot[4];
};