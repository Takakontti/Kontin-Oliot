#ifndef ASIAKAS_H
#define ASIAKAS_H
#include <iostream>
#include "pankkitili.h"
#include "luottotili.h"

using namespace std;

class Asiakas
{
public:
    Asiakas(string, double);
    ~Asiakas();
    string getNimi();
    void showSaldo();
    bool talletus(double);
    bool nosto(double);
    bool luotonMaksu(double);
    bool luotonNosto(double);
    bool tiliSiirto(double, Asiakas &);
private:
    string nimi;
    pankkiTili* kayttotili;
    luottoTili* luottotili;

};

#endif // ASIAKAS_H
