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
    void handleOp(int op);
    void reset();
    void calculation();

private slots:
    void allButtonsClicked();


private:
    Ui::MainWindow *ui;
    QString number1, number2;
    float result = 0;
    int naytto = 0;
    int operand;
};
#endif // MAINWINDOW_H
