#include "notifikaattori.h"
#include "seuraaja.h"
#include <iostream>

using namespace std;

Notifikaattori::Notifikaattori() {
    cout<<"Notifikaattori luotu"<<endl;

}

void Notifikaattori::lisaa(Seuraaja * s)
{
    if (seuraajat == nullptr) {
        seuraajat = s;
    } else {
        Seuraaja * current = seuraajat;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = s;
    }
}

void Notifikaattori::poista(Seuraaja * s)
{
    cout<<"Notifikaattori poistaa seuraajan "<<s->getNimi()<<endl;
    if (seuraajat == nullptr) {
        return;
    }
    if (seuraajat == s) {
        seuraajat = seuraajat->next;
        return;
    }
    Seuraaja * current = seuraajat;
    while (current->next != nullptr) {
        if (current->next == s) {
            current->next = current->next->next;
            return;
        }
        current = current->next;
    }    

}

void Notifikaattori::tulosta()
{
    cout <<"Notifikaattorin seuraajat: "<<endl;
    Seuraaja * current = seuraajat;
    while (current != nullptr) {
        cout<<current->getNimi()<<endl;
        current = current->next;
    }
}

void Notifikaattori::postita(string text)
{
    cout<<"Notifikaattori postittaa viestin: "<<text<<endl;
    Seuraaja * current = seuraajat;
    while (current != nullptr) {
        current->paivitys(text);
        current = current->next;
    }
}
