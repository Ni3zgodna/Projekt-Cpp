#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "matematyka.h"

#include <QKeyEvent>
#include <QObject>

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
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    void onEnterPressed();
    void eq_false();
};

#endif // MAINWINDOW_H
