#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <string>

class Brain
{
public:
    Brain();
    Brain(const Brain& obj);
    Brain& operator=(const Brain& obj);
    ~Brain();
    void setIdeas(const std::string* newIdeas, int size);
    std::string* getIdeas();
private:
    std::string ideas[100];
};

#endif