#include "Projekt.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

int losuj_liczba(int zakres_max, int zakres_min)
{ 
    return zakres_min + std::rand() % (zakres_max - zakres_min + 1);
}

char losuj_symbol()
{
    srand(static_cast<unsigned int>(time(0)));
    // char symbole[5] = {'+', '-', '/', '*', '\0'};
    // return symbole[std::rand() % 4];
    return '*';
}

int mnozenie(char znak, int skladnik_1)
{
    if(999 / skladnik_1 > 100)
        return(999 / skladnik_1 - ((999 / skladnik_1) % 100) * 100);

    return losuj_liczba(999 / skladnik_1, 100 / skladnik_1 + 1);
}

int znajdz_skladnik_2(char znak, int skladnik_1)
{
    if(znak == '*')
        return mnozenie(znak, skladnik_1);

}
