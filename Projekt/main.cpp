#include "Projekt.h"
#include "mainwindow.h"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <utility>

#include <QApplication>

int main(int argc, char *argv[])
{
    srand(static_cast<unsigned int>(time(0)));

    rownanie a;
    a.symbol = losuj_symbol();

    std::pair<int,int> skladniki = znajdz_skladniki(a.symbol);

    a.skladnik_1 = skladniki.first;
    a.skladnik_2 = skladniki.second;

    std::cout << a.skladnik_1 << " ";
    std::cout << a.symbol << " ";
    std::cout << a.skladnik_2 << " ";

    a.rozwiazanie = a.skladnik_1 / a.skladnik_2;
    std::cout << a.rozwiazanie << " ";

    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();

    return 0;
}
