#include "chef.h"


Chef::Chef(string s)
{
    chefName = s;
    cout<<chefName<<" astuu keittiöön"<<endl;
}

Chef::~Chef()
{
    cout<<chefName<<" poistuu keittiöstä"<<endl;
}

string Chef::getName()
{
    return chefName;
}

int Chef::makeSalad(int i)
{
    int salad = (i / 5);
    cout<<chefName<<" voi tehdä "<<i<<" aineksella "<<salad<<" Salaattia"<<endl;
    return salad;
}

int Chef::makeSoup(int i)
{
    int soup = (i / 3);
    cout<<chefName<<" voi tehdä "<<i<<" aineksella "<<soup<<" Keittoa"<<endl;
    return soup;
}



ItalianChef::ItalianChef(string s) : Chef(s)
{
    cout<<"Italian "<<chefName<<" astuu keittiöön"<<endl;
}

ItalianChef::~ItalianChef()
{
    cout<<"Italian "<<chefName<<" poistuu keittiöstä"<<endl;
}

bool ItalianChef::askSecret(string s, int j , int v)
{
    bool cook = false;
    if(s == password) {
        cook = true;
        cout<<"Password ok"<<endl;
        makepizza(j,v);
    }
    else {
        cout<<"Wrong Password"<<endl;
    }
    return cook;
}

int ItalianChef::makepizza(int j, int v)
{
    int pizza = (min(j,v) / 5);
    cout<<chefName<<" voi tehdä "<<j<<" jauholla ja "<<v<<" vedellä "<<pizza<<" pizzaa"<<endl;
    return pizza;
}
