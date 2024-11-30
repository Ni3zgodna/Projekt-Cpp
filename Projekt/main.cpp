#include "matematyka.h"
#include "mainwindow.h"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <utility>

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();

    return 0;
}
