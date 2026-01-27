#include <iostream>
#include "asiakas.h"

using namespace std;

Asiakas user1 ("Matti", 500.0);
Asiakas user2 ("Maija", 300.0);
Asiakas user3 ("Mikko", 1000.0);


int main()
{
    user1.getNimi();
    user1.talletus(200.0);
    user1.nosto(50.0);
    user1.luotonNosto(100.0);
    user1.luotonMaksu(30.0);
    user1.showSaldo();
    user1.tiliSiirto(70.0, user2);
    user1.showSaldo();
    user2.getNimi();
    user2.showSaldo();
    user3.luotonNosto(1200.0);
    user3.getNimi();
    user3.showSaldo();
   
    return 0;
}
