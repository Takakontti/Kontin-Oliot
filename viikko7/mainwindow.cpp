#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupConnections();   
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::reset()
{
    ui->Number_1->clear();
    ui->Number_2->clear();
    ui->Result->clear();
    naytto = 0;
    number1 = "";
    number2 = "";
    result = 0;
}

void MainWindow::handleNum(QString num)
{

    if (naytto == 0) {

        number1.append(num);
        ui->Number_1->setText(number1);
    }
    else {
        number2.append(num);
        ui->Number_2->setText(number2);

    }

    qDebug()<<"Button"<<num<<"Pressed";

}

void MainWindow::handleOp(QString op)
{
    naytto = 1;
    operand = op.toStdString();
    qDebug()<<"Operand"<<operand<<"Selected";
}

void MainWindow::calculation()
{
    float n1 = number1.toFloat();
    float n2 = number2.toFloat();
    if (operand == "+") result = n1 + n2;
    else if (operand == "-") result = n1 - n2;
    else if (operand == "*") result = n1 * n2;
    else if (operand == "/") result = n1 / n2;

    ui->Result->setText(QString::number(result));

}

void MainWindow::setupConnections()
{
    // Löydetään jokainen nappi ja yhdistetään ne loopilla
    const auto buttons = findChildren<QPushButton*>();
    for (QPushButton *btn : buttons) {
        connect(btn, &QPushButton::clicked,
                this, &MainWindow::allButtonsClicked);
    }
}

void MainWindow::allButtonsClicked()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());

    inComp = btn->text().toStdString();

    if(numList.find(inComp) != numList.end())
    {
        handleNum(btn->text());
    }
    else if (opList.find(inComp) != numList.end())
    {
        handleOp(btn->text());
    }
    else if (inComp == "Reset") reset();
    else if (inComp == "Enter") calculation();

    // Deprecated -- dont use the following

    // Löysin tavan yhdistää kaikki napit loopissa, mutta
    // joudun käyttämään ison kasan else if funktioita
    // koska en jaksa etsiä parempaa tapaa tehdä tätä
    // ja tämä on kuitenkin aika luettavaa silti.
    /* if (btn->objectName() == "Num_1") handleNum("1");
    else if (btn->objectName() == "Num_2") handleNum("2");
    else if (btn->objectName() == "Num_3") handleNum("3");
    else if (btn->objectName() == "Num_4") handleNum("4");
    else if (btn->objectName() == "Num_5") handleNum("5");
    else if (btn->objectName() == "Num_6") handleNum("6");
    else if (btn->objectName() == "Num_7") handleNum("7");
    else if (btn->objectName() == "Num_8") handleNum("8");
    else if (btn->objectName() == "Num_9") handleNum("9");
    else if (btn->objectName() == "Num_0") handleNum("0");
    else if (btn->objectName() == "Add") handleOp(0); // +
    else if (btn->objectName() == "Sub") handleOp(1); // -
    else if (btn->objectName() == "Mul") handleOp(2); // *
    else if (btn->objectName() == "Div") handleOp(3); // /
    else if (btn->objectName() == "Reset") reset();
    else if (btn->objectName() == "Enter") calculation();
    */

}
