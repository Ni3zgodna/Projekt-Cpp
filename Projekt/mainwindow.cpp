#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QLineEdit>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setupLineEdits();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setupLineEdits() {

    QRegularExpression znaki("[0-9+_/*]");
    QRegularExpressionValidator *ograniczenie = new QRegularExpressionValidator(znaki, this);

    QList<QLineEdit*> lineEdits = {
        ui->lineEdit_1, ui->lineEdit_2, ui->lineEdit_3, ui->lineEdit_4,
        ui->lineEdit_5, ui->lineEdit_6, ui->lineEdit_7, ui->lineEdit_8
    };


    for (int i = 0; i < lineEdits.size(); i++)
    {
        QLineEdit *lineEdit = lineEdits[i];
        lineEdit->setValidator(ograniczenie);
        lineEdit->setMaxLength(1);

    }
}
