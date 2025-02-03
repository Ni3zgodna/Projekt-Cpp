//#include "mainwindow.h"
//#include "ui_mainwindow.h"
#include "matematyka.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <string>
#include <utility>
#include <vector>

int losuj_liczba(int zakres_max, int zakres_min)
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dis(zakres_min, zakres_max);

    return dis(gen);
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
    return losuj_liczba(118 - skladnik_1, 99 - skladnik_1);
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
        int liczby[] = {100, 102, 104, 105, 106, 108, 110, 112, 114, 115, 116, 
                                118, 120, 124, 125, 126, 128, 130, 132, 134, 135, 136, 
                                138, 140, 142, 144, 145, 146, 148, 150};
        int index = std::rand() % (sizeof(liczby) / sizeof(liczby[0]));
        skladnik_1 = liczby[index];
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
    throw std::logic_error("gŁUPI BŁĄD");
}

rownanie losowanie_rownania()
{
    rownanie a;
    a.symbol = losuj_symbol();

    std::pair<int,int> skladniki = znajdz_skladniki(a.symbol);

    a.skladnik_1 = skladniki.first;
    a.skladnik_2 = skladniki.second;

    switch (a.symbol) {
        case '+':
            a.rozwiazanie =  a.skladnik_1 + a.skladnik_2;
            break;
        case '-':
            a.rozwiazanie =  a.skladnik_1 - a.skladnik_2;
            break;
        case '/':
            a.rozwiazanie = a.skladnik_1 / a.skladnik_2;
            break;
        case '*':
            a.rozwiazanie =  a.skladnik_1 * a.skladnik_2;
            break;
    }

    a.zapis_rownania = std::to_string(a.skladnik_1) + a.symbol + std::to_string(a.skladnik_2) + "=" + std::to_string(a.rozwiazanie);

    std::cout << a.zapis_rownania << "\n";

    if(a.zapis_rownania.size() > 8)
        return losowanie_rownania();

    else
        return a;

}

rownanie zapis_rownania(std::string a)
{
    bool blad = 1;

    rownanie puste;
    puste.zapis_rownania = "Blad";

    rownanie b;
    std::string pom;

    int i = 0;

    for(; i < a.size(); i++)
    {
        if(a[i] != '+' && a[i] != '-' && a[i] != '/'&& a[i] != '*')
            pom += a[i];
        else
        {
            b.symbol = a[i];
            blad = 0;
            break;
        }

    }


    if(blad)
    {
        return puste;
    }

    blad = 1;
    i++;

    b.skladnik_1 = std::stoi(pom);
    pom = {};

    for(; i < a.size(); i++)
    {
        if(a[i] != '=')
            pom += a[i];
            else
        {
            blad = 0;
            break;
        }
    }

    if(blad)
    {
        return puste;
    }

    b.skladnik_2 = std::stoi(pom);

    pom = {};
    i++;

    for(; i < a.size(); i++)
    {
        pom += a[i];
    }

    b.rozwiazanie = std::stoi(pom);
    pom = {};

    switch (b.symbol) {
    case '+':
        if(b.skladnik_1 + b.skladnik_2 != b.rozwiazanie)
            return puste;
        break;
    case '-':
        if(b.skladnik_1 - b.skladnik_2 != b.rozwiazanie)
            return puste;
        break;
    case '/':
        if(b.skladnik_1 / b.skladnik_2 != b.rozwiazanie)
            return puste;
        break;
    case '*':
        if(b.skladnik_1 * b.skladnik_2 != b.rozwiazanie)
            return puste;
        break;
    }

    b.zapis_rownania = std::to_string(b.skladnik_1) + b.symbol + std::to_string(b.skladnik_2) + "=" + std::to_string(b.rozwiazanie);

    return b;
}


