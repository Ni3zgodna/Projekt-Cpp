#include "Projekt.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

int losuj_liczba()
{
    return std::rand() % (1000 + 1);
}

char losuj_symbol()
{
    char symbole[5] = {'+', '-', ':', '*', '\0'};
    return symbole[std::rand() % 4];
}
