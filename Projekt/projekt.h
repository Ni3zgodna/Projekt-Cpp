#ifndef PROJEKT_H
#define PROJEKT_H

#include <string>


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
    int mnozenie(char znak, int skladnik_1);
    int znajdz_skladnik_2(char znak, int skladnik_1);


#endif // PROJEKT_H
