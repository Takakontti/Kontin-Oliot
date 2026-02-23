#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


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
    void handleNum(QString num);
    void handleOp(QString op);
    void reset();
    void calculation();

private slots:
    void allButtonsClicked();


private:
    Ui::MainWindow *ui;
    QString number1, number2;
    float result = 0;
    int naytto = 0;
    std::string operand;
    std::unordered_set<std::string> numList{"0","1","2","3","4","5","6","7","8","9","0"};
    std::unordered_set<std::string> opList{"+","-","*","/"};
    std::string inComp;
};
#endif // MAINWINDOW_H
