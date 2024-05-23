#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>

struct Data {
    int iVal;
    float fVal;
    double dVal;
};

class Serializer {
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
private:
    Serializer();
    Serializer(const Serializer& toCopy);
    Serializer& operator=(const Serializer& toCopy);
    ~Serializer();
};

#endif