//
// Created by Brian Baker on 8/23/23.
//

#include "Effect.h"
#include <string>
using namespace std;

Effect::Effect(string type, int damage, int duration){
    this->type = type;
    this->damage = damage;
    this->duration = duration;
}

Effect::Effect() : Effect("",0,0){}











