#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setupConnections();
    void setTime(int num);
    void setProgress();
    void game();
    void swap();
    void stopGame();
    void setGameInfoText(QString text);
    
public slots:
    void timeout();
    
private slots:
    void allButtonsClicked();

signals:
    

private:
    Ui::MainWindow *ui;
    QString number1, number2;
    short state = 0; // 0=off 1=time set 2=p1 3=p2 4=stopped

    QTimer *timer1;
    QTimer *timer2;
    int timeRemaining1;
    int timeRemaining2;

};
#endif // MAINWINDOW_H
