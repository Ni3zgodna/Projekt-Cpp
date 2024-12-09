#ifndef MATEMATYKA_H
#define MATEMATYKA_H
\
#include <QMainWindow>
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
    rownanie losowanie_rownania();
    rownanie zapis_rownania(std::string a);
    std::pair<int, int> znajdz_skladniki(char znak);


#endif // MATEMATYKA_H
