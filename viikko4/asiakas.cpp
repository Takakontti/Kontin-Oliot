#include "asiakas.h"

Asiakas::Asiakas(string nimi, double raja) {
    this->nimi = nimi;
    this->kayttotili = new pankkiTili(nimi);
    this->luottotili = new luottoTili(nimi, raja);
    cout << "Asiakas " << nimi << " luotu." << endl;
}

Asiakas::~Asiakas()
{
    delete kayttotili;
    delete luottotili;
    cout << "Asiakas " << nimi << " poistettu." << endl;
}

string Asiakas::getNimi()
{
    return nimi;
}

void Asiakas::showSaldo()
{
    cout << "Käyttötilin saldo: " << kayttotili->getBalance() << " euroa." << endl;
    cout << "Luottotilin saldo: " << luottotili->getBalance() << " euroa." << endl;
}

bool Asiakas::talletus(double amount)
{
    return kayttotili->deposit(amount);
}

bool Asiakas::nosto(double amount)
{
    return kayttotili->withdraw(amount);
}

bool Asiakas::luotonMaksu(double amount)
{
    return luottotili->deposit(amount);
}

bool Asiakas::luotonNosto(double amount)
{
    return luottotili->withdraw(amount);
}

bool Asiakas::tiliSiirto(double amount, Asiakas & saaja)
{
    if (this->kayttotili->withdraw(amount)) {
        if (saaja.kayttotili->deposit(amount)) {
            return true;
        } else {
            this->kayttotili->deposit(amount);
            return false;
        }
    }
    return false;
}
