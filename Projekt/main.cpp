#include "Projekt.h"

#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    rownanie a;
    a.skladnik_1 = losuj_liczba();
    a.symbol = losuj_symbol();

    std::cout << a.skladnik_1;
    std::cout << a.symbol;

    return 0;
}
