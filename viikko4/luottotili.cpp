#include "luottotili.h"


luottoTili::luottoTili(string nimi, double raja) : pankkiTili(nimi)
{
    luottoRaja = raja;
    cout << "Luottotili luotu. "<< nimi <<" Luottoraja: " << luottoRaja << " euroa." << endl;
}

luottoTili::~luottoTili()
{
    cout << "Luottotili " << omistaja << " poistettu." << endl;
}

bool luottoTili::withdraw(double amount)
{
    if (amount < 0 || amount > saldo + luottoRaja) {
        return false;
    }
    saldo -= amount;
    return true;
}

bool luottoTili::deposit(double amount)
{
    if (amount < 0 || saldo + amount > 0) {
        return false;
    }
    saldo += amount;
    return true;
}
