#include "Projekt.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <utility>
#include <vector>

int losuj_liczba(int zakres_max, int zakres_min)
{ 
    return zakres_min + std::rand() % (zakres_max - zakres_min + 1);
}

char losuj_symbol()
{
    srand(static_cast<unsigned int>(time(0)));
    char symbole[5] = {'+', '-', '/', '*', '\0'};
    return symbole[std::rand() % 4];
}

int mnozenie(int skladnik_1)
{
    if(999 / skladnik_1 > 100)
        return(999 / skladnik_1 - ((999 / skladnik_1) % 100) * 100);

    return losuj_liczba(999 / skladnik_1, 100 / skladnik_1 + 1);
}

int dzielenie(int skladnik_1)
{
    std::vector<int> dzielniki;

    for (int i = 1; i <= 9; i++)
    {
        if(skladnik_1 % i == 0)
            dzielniki.push_back(i);

    }

    for(int i = 0; i < dzielniki.size(); i++)
        std::cout << dzielniki[i] << "\n";

    int index = std::rand() % dzielniki.size();
    return dzielniki[index];
}

int dodawanie(int skladnik_1)
{
    return losuj_liczba(118 - skladnik_1, 100 - skladnik_1);
}

int odejmowanie(int skladnik_1)
{
    if(skladnik_1 > 100)
        return losuj_liczba(9, 1);
    return losuj_liczba(skladnik_1 - 10, 10);
}

std::pair<int,int> znajdz_skladniki(char znak)
{
    int skladnik_1;

    if(znak == '*')
    {
        skladnik_1 = 1 + std::rand() % 99;
        return std::make_pair(skladnik_1, mnozenie(skladnik_1));
    }
    if(znak == '/')
    {
        skladnik_1 = 100 + std::rand() % (198 - 100 + 1);
        return std::make_pair(skladnik_1, dzielenie(skladnik_1));
    }
    if(znak == '+')
    {
        skladnik_1 = 1 + std::rand() % 99;
        return std::make_pair(skladnik_1, dodawanie(skladnik_1));
    }
    if(znak == '-')
    {
        skladnik_1 = 20 + std::rand() % (108 - 20 + 1);
        return std::make_pair(skladnik_1, odejmowanie(skladnik_1));
    }
}
