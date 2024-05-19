#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(80) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name(name), grade(grade) {}

Bureaucrat::~Bureaucrat() {}

