#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "matematyka.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QStringList getCollectedValues() const;

private:
    Ui::MainWindow *ui;
    rownanie wylosowane;
    rownanie zgadywane;

    void setupLineEdits();

private slots:
    void onEnterPressed();
    void eq_false();
};

#endif // MAINWINDOW_H
