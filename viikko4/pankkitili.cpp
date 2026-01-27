#include "pankkitili.h"

pankkiTili::pankkiTili(string nimi) {
    saldo = 0.0;
    omistaja = nimi;
    cout << "Pankkitili luotu."<< nimi << endl;
}

pankkiTili::~pankkiTili()
{
    cout << "Pankkitili " << omistaja << " poistettu." << endl;
}

double pankkiTili::getBalance()
{
    return saldo;
}

bool pankkiTili::deposit(double amount)
{
    if (amount < 0) {
        return false;
    }
    saldo += amount;
    return true;
}

bool pankkiTili::withdraw(double amount)
{
    if (amount < 0 || amount > saldo) {
        return false;
    }
    saldo -= amount;
    return true;
}
