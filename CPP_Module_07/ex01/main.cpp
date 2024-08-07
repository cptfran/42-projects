#include <iostream>
#include "iter.hpp"

int main()
{
    int iNums[] = {1, 2, 3, 4 ,5};
    std::string words[] = {"42", "wolfsburg"};
    float fNums[] = {1.0f, 2.0f, 3.0f};
    ::iter(iNums, sizeof(iNums) / sizeof(*iNums), ::printArg);
    ::iter(words, words->length(), ::printArg);
    ::iter(fNums, sizeof(fNums) / sizeof(*fNums), ::printArg);
    return 0;
}