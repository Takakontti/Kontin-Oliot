#ifndef PANKKITILI_H
#define PANKKITILI_H
#include <string>
#include <iostream>

using namespace std;

class pankkiTili
{
public:
    pankkiTili(string);
    ~pankkiTili();
    double getBalance();
    virtual bool deposit(double);
    virtual bool withdraw(double);

protected:
    string omistaja;
    double saldo;

};

#endif // PANKKITILI_H
