//
// Created by Brian Baker on 8/23/23.
//

#ifndef FRESNOFANTASYVI_FIGHTER_H
#define FRESNOFANTASYVI_FIGHTER_H

#include "Player.h"
using namespace std;

class Fighter : public Player {
private:
    int numberOfPotions;
public:
    Fighter(string name);
    bool specialOne(Player *target) override;
    bool specialTwo(Player *target) override;
    bool takeDamage(int damage) override;
    string status() override;
};


#endif //FRESNOFANTASYVI_FIGHTER_H
