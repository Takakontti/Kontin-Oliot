#include "seuraaja.h"
#include <iostream>

Seuraaja::Seuraaja(string name) {
    nimi = name;
    cout<<"Seuraaja "<<nimi<<" luotu"<<endl;

}

string Seuraaja::getNimi()
{
    return string(nimi);
}

void Seuraaja::paivitys(string text)
{
    cout<<"Seuraaja "<<nimi<<" sai viestin: "<<text<<endl;

}
