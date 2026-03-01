#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timer1(new QTimer(this))
    , timer2(new QTimer(this))
    , timeRemaining1(0)
    , timeRemaining2(0)
{
    ui->setupUi(this);
    ui->gameInfo->setAlignment(Qt::AlignCenter);

    setupConnections();   
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTime(int num)
{
    timeRemaining1 = num;
    timeRemaining2 = num;

    ui->progressBar1->setMaximum(num);
    ui->progressBar1->setValue(num);

    ui->progressBar2->setMaximum(num);
    ui->progressBar2->setValue(num);
    
    qDebug()<<timeRemaining1<<timeRemaining2;
    state = 1;
    setGameInfoText("Time set. Press Start to begin the game.");
}

void MainWindow::game()
{
    if (state == 1)
    {
    state = 2;
    timer1->start(1000);
    setGameInfoText("Game ongoing.");
    }
}

void MainWindow::swap()
{
    if (state == 2) {
        state = 3;
        timer1->stop();
        timer2->start(1000);
    } else if (state == 3) {
        state = 2;
        timer2->stop();
        timer1->start(1000);
    }
}

void MainWindow::timeout()
{
    if (state == 2) {
        if (timeRemaining1 > 0) {
            --timeRemaining1;
            ui->progressBar1->setValue(timeRemaining1);
            qDebug()<<timeRemaining1;
        } else {
            timer1->stop();
            stopGame();
            qDebug() << "Player 1 time elapsed";
            setGameInfoText("Player 2 wins!");
        }

    } else if (state == 3) {
        if (timeRemaining2 > 0) {
            --timeRemaining2;
            ui->progressBar2->setValue(timeRemaining2);
            qDebug()<<timeRemaining2;
        } else {
            timer2->stop();
            stopGame();
            qDebug() << "Player 2 time elapsed";
            setGameInfoText("Player 1 wins!");
        }
    }

}

void MainWindow::stopGame()
{
    state = 4;
    timer1->stop();
    timer2->stop();
    setGameInfoText("Game Over");
    QTimer::singleShot(2000, this, [this](){
        setGameInfoText("Select time and press Start to begin a new game.");
        state = 0;
    });

}

void MainWindow::setGameInfoText(QString text)
{
    ui->gameInfo->setText(text);
}

void MainWindow::setupConnections()
{
    const auto buttons = findChildren<QPushButton*>();
    for (QPushButton *btn : buttons) {
        connect(btn, &QPushButton::clicked,
                this, &MainWindow::allButtonsClicked);
    }
    connect(timer1, &QTimer::timeout, this, &MainWindow::timeout);
    connect(timer2, &QTimer::timeout, this, &MainWindow::timeout);

}

void MainWindow::allButtonsClicked()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());

    if (btn->objectName() == "Time1") setTime(120);
    else if (btn->objectName() == "Time2") setTime(300);
    else if (btn->objectName() == "Start") game();
    else if (btn->objectName() == "Switch") swap();
    else if (btn->objectName() == "Stop") stopGame();

    qDebug()<<btn->objectName()<<"pressed";

}
