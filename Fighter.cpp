//
// Created by Brian Baker on 8/23/23.
//

#include "Fighter.h"
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Fighter::Fighter(string name) : Player(name) {
    health = 100;
    resource = 0;
    resourceName = "Rage";
    strength = 20;
    armor = 10;
    speed = 20;
    criticalChance = 10;
    accuracy = 80;
    specialOneName = "Drink Potion";
    specialTwoName = "Execute";
    specialOneCost = 0;
    specialTwoCost = 0;
    numberOfPotions = 3;
}

bool Fighter::specialOne(Player *target){
    srand(time(NULL));
    if (numberOfPotions > 0){
        numberOfPotions--;
        int healing = rand() % 20 + 10;
        cout << this->name << " deftly guzzles a healing potion healing them for "
             << healing << " points of health.\n\n";
        this->health += healing;
    }
    else {
        cout << "Silly goose, you don't have any potions. You lose a turn.\n\n";
    }
}

bool Fighter::specialTwo(Player *target){
    srand(time(NULL));
    int rollToHit = rand() % 100 + 1;
    if (this->accuracy < rollToHit){
        cout << this->name << " attempts to strike " << target->getName()
             << ", but embarrassingly strikes nothing but air\n"
             << "and damages nothing, but their own ego.\n\n";
        return false;
    }
    int damage = rand() % strength + strength + (resource * 1.5);
    cout << this->name << " shouts a primal shout and leaps into the air coming down "
         << " upon\n" << target->getName() << " in a fierce violent attack dealing "
         << damage << " points of damage.\n\n";
    resource = 0;
    return target->takeDamage(damage);
}

bool Fighter::takeDamage(int damage) {
    this->resource += damage / 2;
    return Player::takeDamage(damage);
}

string Fighter::status() {
    return Player::status() + "  Potions: " + to_string(this->numberOfPotions);
}