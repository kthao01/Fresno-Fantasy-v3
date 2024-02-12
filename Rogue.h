//
// Created by Brian Baker on 8/28/23.
//

#ifndef FRESNOFANTASYVI_ROGUE_H
#define FRESNOFANTASYVI_ROGUE_H

#include <string>
#include "Player.h"
using namespace std;

class Rogue : public Player {
public:
    Rogue(string name);
    bool specialOne(Player* target);
    bool specialTwo(Player* target);
    bool processEffects(bool &loseTurn) override;
};


#endif //FRESNOFANTASYVI_ROGUE_H
