#include <iostream>
#include "Array.hpp"

int main()
{
    // Test default constructor
    Array<int> a;
    std::cout << "Size of a: " << a.size() << std::endl;

    // Test constructor with size
    Array<int> b(5);
    std::cout << "Size of b: " << b.size() << std::endl;

    // Test operator[]
    for (unsigned int i = 0; i < b.size(); i++)
    {
        b[i] = i;
    }

    // Test copy constructor
    Array<int> c(b);
    std::cout << "Size of c: " << c.size() << std::endl;

    // Test operator=
    a = c;
    std::cout << "Size of a: " << a.size() << std::endl;

    // Test values
    for (unsigned int i = 0; i < a.size(); i++)
    {
        std::cout << "a[" << i << "] = " << a[i] << std::endl;
    }

    // Test exception
    try
    {
        std::cout << "a[10] = " << a[10] << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}