#include <iostream>
#include <cstdlib>

using namespace std;

//osa 1
/*
int main()
{
    srand(time(0));

    int num = (rand() % 20)+1;
    int guess = 0;
    bool game = 1;

    while(game == 1) {
        cout<<"Syötä numero"<<endl;
        cin>>guess;

        if(guess == num) {
            cout<<"Oikein"<<endl;
            game = 0;
        }
        else if(guess < num) {
            cout<<"Liian pieni"<<endl;
        }
        else if(guess > num) {
            cout<<"Liian suuri"<<endl;
        }
        else {
            cout<<"Virheelinen syöte"<<endl;
        }
    }


    return 0;
}
*/

//osa 2
/*
int game() {
    srand(time(0));

    int num = (rand() % 20)+1;
    int guess = 0;
    int attempts = 0;
    bool game = 1;

    while(game == 1) {
        cout<<"Syötä numero"<<endl;
        cin>>guess;

        if(guess == num) {
            cout<<"Oikein"<<endl;
            game = 0;
        }
        else if(guess < num) {
            cout<<"Liian pieni"<<endl;
        }
        else if(guess > num) {
            cout<<"Liian suuri"<<endl;
        }
        else {
            cout<<"Virheelinen syöte"<<endl;
        }
        attempts++;
    }

    return attempts;
}

int main() {

    int value = game();

    cout<<"Yritykset: "<<value<<endl;

    return 0;
}
*/

//osa 3
int game(int max) {
    srand(time(0));

    int num = (rand() % max)+1;
    int guess = 0;
    int attempts = 0;
    bool game = 1;

    while(game == 1) {
        cout<<"Syötä numero"<<endl;
        cin>>guess;

        if(guess == num) {
            cout<<"Oikein"<<endl;
            game = 0;
        }
        else if(guess < num) {
            cout<<"Liian pieni"<<endl;
        }
        else if(guess > num) {
            cout<<"Liian suuri"<<endl;
        }
        else {
            cout<<"Virheelinen syöte"<<endl;
        }
        attempts++;
    }

    return attempts;
}

int main() {

    int value = game(40);

    cout<<"Yritykset: "<<value<<endl;

    return 0;
}
