#ifndef CHEF_H
#define CHEF_H
#include <iostream>

using namespace std;

class Chef
{

public:
    Chef(string);
    ~Chef();

    string getName();
    int makeSalad(int);
    int makeSoup(int);


protected:
    string chefName;

};

class ItalianChef : public Chef
{

public:
    ItalianChef(string);
    ~ItalianChef();

    bool askSecret(string, int, int);

private:
    int makepizza(int, int);

    string password = "pizza";
    int flour;
    int water;

};

#endif // CHEF_H
