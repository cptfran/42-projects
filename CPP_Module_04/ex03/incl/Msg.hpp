#ifndef MSG_HPP
#define MSG_HPP
#include "Colors.hpp"

//AMateria class
#define MSG_AMATERIA_DEFAULT_CONSTRUCTOR LIGHT_GREEN "Default AMateria constructor called" RESET
#define MSG_AMATERIA_ASSIGN_TYPE_CONSTRUCTOR LIGHT_GREEN "Assign type AMateria constructor called" RESET
#define MSG_AMATERIA_DESTRUCTOR RED "AMateria destructor called" RESET
#define MSG_AMATERIA_USE_DEFAULT "AMateria use() func called" RESET

//Ice class
#define MSG_ICE_DEFAULT_CONSTRUCTOR LIGHT_GREEN "Default Ice constructor called" RESET
#define MSG_ICE_ASSIGN_TYPE_CONSTRUCTOR LIGHT_GREEN "Assign type Ice constructor called" RESET
#define MSG_ICE_DESTRUCTOR RED "Ice destructor called" RESET
#define MSG_ICE_CLONE LIGHT_GREEN "Ice clone() func called"

//Cure class
#define MSG_CURE_DEFAULT_CONSTRUCTOR LIGHT_GREEN "Default Cure constructor called" RESET
#define MSG_CURE_ASSIGN_TYPE_CONSTRUCTOR LIGHT_GREEN "Assign type Cure constructor called" RESET
#define MSG_CURE_DESTRUCTOR RED "Cure destructor called" RESET
#define MSG_CURE_CLONE LIGHT_GREEN "Cure clone() func called"

//Character class
#define MSG_CHARACTER_DEFAULT_CONSTRUCTOR LIGHT_GREEN "Default Character constructor called" RESET
#define MSG_CHARACTER_ASSIGN_TYPE_CONSTRUCTOR LIGHT_GREEN "Assign type Character constructor called" RESET
#define MSG_CHARACTER_COPY_CONSTRUCTOR LIGHT_GREEN "Character copy constructor called" RESET
#define MSG_CHARACTER_COPY_ASSIGNMENT LIGHT_GREEN "Character copy assignment operator called" RESET
#define MSG_CHARACTER_DESTRUCTOR RED "Character destructor called" RESET
#define MSG_CHARACTER_EQUIP LIGHT_GREEN "Character equip() func called" RESET
#define ERR_CHARACTER_EQUIP RED << "Character cannot equip(): full inventory or materia not created" RESET
#define MSG_CHARACTER_UNEQUIP LIGHT_GREEN "Character unequip() func called" RESET
#define ERR_CHARACTER_UNEQUIP RED "Character cannot unequip(): wrong index" RESET

//MateriaSource class
#define MSG_MATERIASOURCE_DEFAULT_CONSTRUCTOR LIGHT_GREEN "Default MateriaSource constructor called" RESET
#define MSG_MATERIASOURCE_COPY_CONSTRUCTOR LIGHT_GREEN "MateriaSource copy constructor called" RESET
#define MSG_MATERIASOURCE_COPY_ASSIGNMENT LIGHT_GREEN "MateriaSource copy assignment operator called" RESET
#define MSG_MATERIASOURCE_DESTRUCTOR RED "MateriaSource destructor called" RESET
#define MSG_MATERIASOURCE_LEARN_MATERIA LIGHT_GREEN "MateriaSource learnMateria() func called" RESET
#define ERR_MATERIASOURCE_LEARN_MATERIA RED "MateriaSource cannot learnMateria(): full slots" RESET
#define MSG_MATERIASOURCE_CREATE_MATERIA LIGHT_GREEN "MateriaSource createMateria() func called" RESET
#define ERR_MATERIASOURCE_CREATE_MATERIA RED "MateriaSource cannot createMateria(): materia not learned or full slots" RESET

//main
#define MSG_CHOOSE_ACTION BLUE "Choose action:\n'learnMateria' 'createMateria' 'equip' 'unequip' 'use' 'exit'" RESET
#define MSG_CHOOSE_MATERIA BLUE "Choose materia:\n'ice' 'cure'" RESET
#define MSG_CHOOSE_INDEX BLUE "Choose index: (0 - 3)" RESET
#define MSG_CHOOSE_TARGET BLUE "Choose target:\n'target1' 'target2'" RESET
#define ERR_WRONG_CMD RED "Unknown command" RESET
#endif