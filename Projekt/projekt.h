#ifndef PROJEKT_H
#define PROJEKT_H

#include <string>
#include <utility>


struct rownanie
{
    char symbol;
    std::string zapis_rownania;
    int skladnik_1;
    int skladnik_2;
    int rozwiazanie;
};

    int losuj_liczba(int zakres_max, int zakres_min);
    char losuj_symbol();
    std::pair<int, int> znajdz_skladniki(char znak);


#endif // PROJEKT_H
