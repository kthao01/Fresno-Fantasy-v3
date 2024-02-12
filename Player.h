//
// Created by Brian Baker on 8/23/23.
//

#ifndef FRESNOFANTASYVI_PLAYER_H
#define FRESNOFANTASYVI_PLAYER_H

#include "Effect.h"
#include <string>
#include <vector>
using namespace std;

class Player {
protected:
    string name;
    int health;
    int resource;
    string resourceName;
    int strength;
    int armor;
    int speed;
    int criticalChance;
    int accuracy;
    vector<Effect> effects;
    string specialOneName;
    int specialOneCost;
    string specialTwoName;
    int specialTwoCost;
    int level;
public:
    Player(string name);
    const string &getName() const;
    void setName(const string &name);
    int getHealth() const;
    void setHealth(int health);
    int getResource() const;
    void setResource(int resource);
    const string &getResourceName() const;
    void setResourceName(const string &resourceName);
    int getArmor() const;
    void setArmor(int armor);
    int getSpeed() const;
    void setSpeed(int speed);
    int getCriticalChance() const;
    void setCriticalChance(int criticalChance);
    int getAccuracy() const;
    void setAccuracy(int accuracy);
    vector<Effect> &getEffects();
    void setEffects(const vector<Effect> &effects);
    const string &getSpecialOneName() const;
    void setSpecialOneName(const string &specialOneName);
    int getSpecialOneCost() const;
    void setSpecialOneCost(int specialOneCost);
    const string &getSpecialTwoName() const;
    void setSpecialTwoName(const string &specialTwoName);
    int getSpecialTwoCost() const;
    void setSpecialTwoCost(int specialTwoCost);
    int getLevel() const;
    void setLevel(int level);
    int getStrength() const;
    void setStrength(int strength);
    virtual bool attack(Player* target);
    virtual bool takeDamage(int damage);
    virtual bool specialOne(Player* target) = 0;
    virtual bool specialTwo(Player* target) = 0;
    virtual bool processEffects(bool &loseTurn);
    virtual void die();
    virtual string status();
};


#endif //FRESNOFANTASYVI_PLAYER_H
