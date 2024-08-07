#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data values;
    values.dVal = 2;
    std::cout << values.dVal << std::endl;
    const uintptr_t val = Serializer::serialize(&values);
    Data *data = Serializer::deserialize(val);
    std::cout << data->dVal << std::endl;
    std::cout << &values << "\n" << data << std::endl;
    return 0;
}