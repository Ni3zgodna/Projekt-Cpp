#include "Projekt.h"

#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    rownanie a;
    a.skladnik_1 = losuj_liczba(99, 1);
    a.symbol = losuj_symbol();

    std::cout << a.skladnik_1 << " ";
    std::cout << a.symbol << " ";

    a.skladnik_2 = znajdz_skladnik_2(a.symbol, a.skladnik_1);

    std::cout << a.skladnik_2 << " ";

    a.rozwiazanie = a.skladnik_1 * a.skladnik_2;
    std::cout << a.rozwiazanie << " ";

    return 0;
}
