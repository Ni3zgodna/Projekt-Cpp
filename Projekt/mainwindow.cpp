#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "matematyka.h"

#include <iostream>
#include <QLineEdit>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QDebug>

int runda = 1;
bool blad = 0;

QList<QLineEdit*> lineEdits;
QList<QLineEdit*> all_lineEdits;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    wylosowane = losowanie_rownania();
    setupLineEdits();

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setupLineEdits() {

    QRegularExpression znaki("[0-9=+-/*]");
    QRegularExpressionValidator *ograniczenie = new QRegularExpressionValidator(znaki, this);

    all_lineEdits = {
        ui->lineEdit_1_1, ui->lineEdit_1_2, ui->lineEdit_1_3, ui->lineEdit_1_4,
        ui->lineEdit_1_5, ui->lineEdit_1_6, ui->lineEdit_1_7, ui->lineEdit_1_8,

        ui->lineEdit_2_1, ui->lineEdit_2_2, ui->lineEdit_2_3, ui->lineEdit_2_4,
        ui->lineEdit_2_5, ui->lineEdit_2_6, ui->lineEdit_2_7, ui->lineEdit_2_8,

        ui->lineEdit_3_1, ui->lineEdit_3_2, ui->lineEdit_3_3, ui->lineEdit_3_4,
        ui->lineEdit_3_5, ui->lineEdit_3_6, ui->lineEdit_3_7, ui->lineEdit_3_8,

        ui->lineEdit_4_1, ui->lineEdit_4_2, ui->lineEdit_4_3, ui->lineEdit_4_4,
        ui->lineEdit_4_5, ui->lineEdit_4_6, ui->lineEdit_4_7, ui->lineEdit_4_8,

        ui->lineEdit_5_1, ui->lineEdit_5_2, ui->lineEdit_5_3, ui->lineEdit_5_4,
        ui->lineEdit_5_5, ui->lineEdit_5_6, ui->lineEdit_5_7, ui->lineEdit_5_8,

        ui->lineEdit_6_1, ui->lineEdit_6_2, ui->lineEdit_6_3, ui->lineEdit_6_4,
        ui->lineEdit_6_5, ui->lineEdit_6_6, ui->lineEdit_6_7, ui->lineEdit_6_8,

        ui->lineEdit_7_1, ui->lineEdit_7_2, ui->lineEdit_7_3, ui->lineEdit_7_4,
        ui->lineEdit_7_5, ui->lineEdit_7_6, ui->lineEdit_7_7, ui->lineEdit_7_8,

        ui->lineEdit_8_1, ui->lineEdit_8_2, ui->lineEdit_8_3, ui->lineEdit_8_4,
        ui->lineEdit_8_5, ui->lineEdit_8_6, ui->lineEdit_8_7, ui->lineEdit_8_8
    };

    for (QLineEdit *lineEdit : all_lineEdits)
    {
        lineEdit->setEnabled(false);
    }

    switch (runda) {
    case 1:
        lineEdits = {
            ui->lineEdit_1_1, ui->lineEdit_1_2, ui->lineEdit_1_3, ui->lineEdit_1_4,
            ui->lineEdit_1_5, ui->lineEdit_1_6, ui->lineEdit_1_7, ui->lineEdit_1_8
        };
        break;
    case 2:
        lineEdits = {
            ui->lineEdit_2_1, ui->lineEdit_2_2, ui->lineEdit_2_3, ui->lineEdit_2_4,
            ui->lineEdit_2_5, ui->lineEdit_2_6, ui->lineEdit_2_7, ui->lineEdit_2_8,
        };
        break;
    case 3:
        lineEdits = {
            ui->lineEdit_3_1, ui->lineEdit_3_2, ui->lineEdit_3_3, ui->lineEdit_3_4,
            ui->lineEdit_3_5, ui->lineEdit_3_6, ui->lineEdit_3_7, ui->lineEdit_3_8,
        };
        break;
    case 4:
        lineEdits = {
            ui->lineEdit_4_1, ui->lineEdit_4_2, ui->lineEdit_4_3, ui->lineEdit_4_4,
            ui->lineEdit_4_5, ui->lineEdit_4_6, ui->lineEdit_4_7, ui->lineEdit_4_8,
        };
        break;
    case 5:
        lineEdits = {
            ui->lineEdit_5_1, ui->lineEdit_5_2, ui->lineEdit_5_3, ui->lineEdit_5_4,
            ui->lineEdit_5_5, ui->lineEdit_5_6, ui->lineEdit_5_7, ui->lineEdit_5_8,
        };
        break;
    case 6:
        lineEdits = {
            ui->lineEdit_6_1, ui->lineEdit_6_2, ui->lineEdit_6_3, ui->lineEdit_6_4,
            ui->lineEdit_6_5, ui->lineEdit_6_6, ui->lineEdit_6_7, ui->lineEdit_6_8,
        };
        break;
    case 7:
        lineEdits = {
            ui->lineEdit_7_1, ui->lineEdit_7_2, ui->lineEdit_7_3, ui->lineEdit_7_4,
            ui->lineEdit_7_5, ui->lineEdit_7_6, ui->lineEdit_7_7, ui->lineEdit_7_8,
        };
        break;
    case 8:
        lineEdits = {
            ui->lineEdit_8_1, ui->lineEdit_8_2, ui->lineEdit_8_3, ui->lineEdit_8_4,
            ui->lineEdit_8_5, ui->lineEdit_8_6, ui->lineEdit_8_7, ui->lineEdit_8_8
        };
        break;
    case 9:
        lineEdits = {};
        break;
    }
    for (QLineEdit *lineEdit : lineEdits)
    {
        if(!blad)
            lineEdit->setStyleSheet("border: 1px solid orange; font-size: 20px; text-align: center;");

        lineEdit->setEnabled(true);
        lineEdit->setValidator(ograniczenie);
        lineEdit->setMaxLength(1);

        connect(lineEdit, &QLineEdit::returnPressed, this, &MainWindow::onEnterPressed);
    }
}

void MainWindow::onEnterPressed() {

    QStringList values;
    for (QLineEdit *lineEdit : lineEdits) {
        values.append(lineEdit->text());
    }

    std::string wartosci;

    for (QString &value : values) {
        wartosci += value.toStdString();
    }

    zgadywane = zapis_rownania(wartosci);

    if(zgadywane.zapis_rownania == "Blad")
        eq_false();
    else
    {
        runda++;

        for (QLineEdit *lineEdit : lineEdits)
            lineEdit->setStyleSheet("border: 1px solid black; font-size: 20px; text-align: center;");

        blad = 0;
        setupLineEdits();
    }
}

void MainWindow::eq_false()
{
    for (QLineEdit *lineEdit : lineEdits)
        lineEdit->setStyleSheet("border: 1px solid red; font-size: 20px; text-align: center;");
    blad = 1;
    setupLineEdits();
}

