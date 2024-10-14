#ifndef PROJEKT_H
#define PROJEKT_H

#include <string>


struct rownanie
{
    std::string symbol;
    std::string zapis_rownania;
    int skladnik_1;
    int skladnik_2;
    int rozwiazanie;
};

    int losuj_liczba();
    char losuj_symbol();


#endif // PROJEKT_H
