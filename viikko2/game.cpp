#include "game.h"
#include <iostream>

using namespace std;

Game::Game(int m)
{
    maxNumber = m;
    cout<<"GAME CONSTURCTOR: object initialized with "<<maxNumber<<" as a maximum value"<<endl;
}

Game::~Game()
{
    cout<<"GAME DESTRUCTOR: object cleared from stack memory"<<endl;
}

void Game::play()
{
    srand(time(0));

    randomNumber = (rand() % maxNumber) + 1;
    playerGuess = 0;
    numOfGuesses = 0;

    bool run = true;

    while(run) {
        cout<<"Syötä numero väliltä 1 - "<<maxNumber<<endl;

        cin>>playerGuess;

        if(playerGuess == randomNumber) {
            run = false;

        }
        else if (playerGuess < randomNumber) {
            cout<<"Liian pieni"<<endl;
        }
        else if (playerGuess > randomNumber) {
            cout<<"Liian iso"<<endl;
        }
        else {
            cout<<"Virheellinen syöte"<<endl;
        }

        numOfGuesses++;

    }

    printGameResult();

}

void Game::printGameResult()
{
    cout<<"Oikein numero oli: "<<randomNumber<<endl;
    cout<<"Yritykset: "<<numOfGuesses<<endl;
}
