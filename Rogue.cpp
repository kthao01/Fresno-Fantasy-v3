//
// Created by Brian Baker on 8/28/23.
//

#include "Rogue.h"
#include "Player.h"
#include "Effect.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

Rogue::Rogue(string name) : Player(name){
    health = 80;
    resource = 100;
    resourceName = "Stamina";
    strength = 10;
    armor = 5;
    speed = 40;
    criticalChance = 15;
    accuracy = 75;
    specialOneName = "Stun";
    specialTwoName = "Poison";
    specialOneCost = 60;
    specialTwoCost = 30;
}

bool Rogue::specialOne(Player* target){
    srand(time(NULL));
    if (this->resource < this->specialOneCost){
        cout << "Silly goose you do not have enough stamina for that.\n\n";
        return false;
    }
    this->resource -= this->specialOneCost;
    int toHit = rand() % 100 + 1;
    if(toHit < this->accuracy){
        int duration = rand() % 3 + 1;
        Effect stun("Stun", 0, duration);
        target->getEffects().push_back(stun);
        cout << this->name << " swings a lead pipe at the back of " << target->getName()
             << " and stuns them for " << duration << " rounds.\n\n";
    }
    else {
        cout << this->name << " attempts to stun their opponent,\n"
             << "but misses and only stuns themselves with their inepitude.\n\n";
    }
}

bool Rogue::specialTwo(Player* target){
    srand(time(NULL));
    if (this->resource < this->specialTwoCost){
        cout << "Silly goose you do not have enough stamina for that.\n\n";
        return false;
    }
    this->resource -= this->specialTwoCost;
    int toHit = rand() % 100 + 1;
    if(toHit < this->accuracy){
        int damage = rand() % 11 + 5;
        Effect poison("Poison", damage, 3);
        target->getEffects().push_back(poison);
        cout << this->name << " throws a poisoned dart at " << target->getName()
             << " and taints their blood with\nquickly acting poison causing "
             << damage << " points of damage for the next 3 rounds.\n\n";
    }
    else {
        cout << this->name << " attempts to poison their opponent,\n"
             << "but misses and cries.\n\n";
    }
}

bool Rogue::processEffects(bool &loseTurn){
    this->resource += 15;
    return Player::processEffects(loseTurn);
}