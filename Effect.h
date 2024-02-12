//
// Created by Brian Baker on 8/23/23.
//

#ifndef FRESNOFANTASYVI_EFFECT_H
#define FRESNOFANTASYVI_EFFECT_H

#include <string>
using namespace std;

class Effect {
public:
    string type;
    int damage;
    int duration;

    Effect();
    Effect(string type, int damage, int duration);
};


#endif //FRESNOFANTASYVI_EFFECT_H
