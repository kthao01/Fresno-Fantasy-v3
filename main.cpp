#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Player.h"
#include "Fighter.h"
#include "Rogue.h"


Player* selectCharacter(){
    int choice = 0;
    string name, temp;
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Choose your character...\n"
         << "1. Fighter\n"
         << "2. Rogue\n"
         << "Enter choice: ";
    getline(cin, temp);
    choice = stoi(temp);
    if(choice == 1){
        return new Fighter(name);
    }
    else if(choice == 2){
        return new Rogue(name);
    }
    else{
        return nullptr;
    }
}

int main() {
    srand(time(NULL));

    // Character Selection Phase
    Player* playerOne = selectCharacter();
    Player* playerTwo = selectCharacter();
    Player *currentPlayer, *targetPlayer, *temp;

    // Coin Flip to Determine Who Attacks First
    int p1Iniative = rand() % 100 + playerOne->getSpeed();
    int p2Iniative = rand() % 100 + playerTwo->getSpeed();
    if(p1Iniative >= p2Iniative){
        currentPlayer = playerOne;
        targetPlayer = playerTwo;
    }
    else {
        currentPlayer = playerTwo;
        targetPlayer = playerOne;
    }

    // Game Variables
    bool endGame = false;
    int choice = 0;
    string s = "";
    bool loseTurn = false;

    // Game Loop
    while(!endGame){

        // Swap Turns
        temp = currentPlayer;
        currentPlayer = targetPlayer;
        targetPlayer = temp;

        // Process Effects
        endGame = currentPlayer->processEffects(loseTurn);
        if(loseTurn || endGame){
            loseTurn = false;
            continue;
        }

        // Display Status
        cout << "========================================================================\n"
             << currentPlayer->getName() << "'s Turn\n"
             << "========================================================================\n";
        cout << currentPlayer->status() << endl;
        cout << targetPlayer->status() << endl;
        cout << "========================================================================\n"
             << "1. Attack\n"
             << "2. " << currentPlayer->getSpecialOneName() << endl
             << "3. " << currentPlayer->getSpecialTwoName() << endl
             << "========================================================================\n"
             << "Enter Choice: ";
        getline(cin, s);
        choice = stoi(s);

        // Take User Action
        switch(choice){
            case 1:
                endGame = currentPlayer->attack(targetPlayer);
                break;
            case 2:
                endGame = currentPlayer->specialOne(targetPlayer);
                break;
            case 3:
                endGame = currentPlayer->specialTwo(targetPlayer);
                break;
            default:
                cout << "Invalid Choice you silly goose, you lost your turn.\n\n";
        }

    }


    // Display Ending Death Message of Loser
    if(playerOne->getHealth() <= 0)
        playerOne->die();
    if(playerTwo->getHealth() <= 0)
        playerTwo->die();


    return 0;
}

