//
// Created by Brian Baker on 8/23/23.
//

#include "Player.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <iostream>
using namespace std;


Player::Player(string name){
    this->name = name;
    this->level = 1;
}

const string &Player::getName() const {
    return name;
}

void Player::setName(const string &name) {
    Player::name = name;
}

int Player::getHealth() const {
    return health;
}

void Player::setHealth(int health) {
    Player::health = health;
}

int Player::getResource() const {
    return resource;
}

void Player::setResource(int resource) {
    Player::resource = resource;
}

const string &Player::getResourceName() const {
    return resourceName;
}

void Player::setResourceName(const string &resourceName) {
    Player::resourceName = resourceName;
}

int Player::getArmor() const {
    return armor;
}

void Player::setArmor(int armor) {
    Player::armor = armor;
}

int Player::getSpeed() const {
    return speed;
}

void Player::setSpeed(int speed) {
    Player::speed = speed;
}

int Player::getCriticalChance() const {
    return criticalChance;
}

void Player::setCriticalChance(int criticalChance) {
    Player::criticalChance = criticalChance;
}

int Player::getAccuracy() const {
    return accuracy;
}

void Player::setAccuracy(int accuracy) {
    Player::accuracy = accuracy;
}

vector<Effect> &Player::getEffects() {
    return effects;
}

void Player::setEffects(const vector<Effect> &effects) {
    Player::effects = effects;
}

const string &Player::getSpecialOneName() const {
    return specialOneName;
}

void Player::setSpecialOneName(const string &specialOneName) {
    Player::specialOneName = specialOneName;
}

int Player::getSpecialOneCost() const {
    return specialOneCost;
}

void Player::setSpecialOneCost(int specialOneCost) {
    Player::specialOneCost = specialOneCost;
}

const string &Player::getSpecialTwoName() const {
    return specialTwoName;
}

void Player::setSpecialTwoName(const string &specialTwoName) {
    Player::specialTwoName = specialTwoName;
}

int Player::getSpecialTwoCost() const {
    return specialTwoCost;
}

void Player::setSpecialTwoCost(int specialTwoCost) {
    Player::specialTwoCost = specialTwoCost;
}

int Player::getLevel() const {
    return level;
}

void Player::setLevel(int level) {
    Player::level = level;
}

int Player::getStrength() const {
    return strength;
}

void Player::setStrength(int strength) {
    Player::strength = strength;
}

bool Player::attack(Player* target){
    srand(time(NULL));
    int rollToHit = rand() % 100 + 1;
    if (this->accuracy < rollToHit){
        cout << this->name << " attempts to strike " << target->name
             << ", but embarrassingly strikes nothing but air\n"
             << "and damages nothing, but their own ego.\n\n";
        return false;
    }
    else {
        bool crit = (rand() % 100 + 1) <= this->criticalChance;
        int damage = rand() % this->strength + this->strength;
        if (!crit) {
            cout << this->name << " lashes out with their weapon at " << target->name
                 << " and strikes them\nright in the meaty bits causing "
                 << damage << " points of damage.\n\n";
            return target->takeDamage(damage);
        }
        else{
            damage = damage * 2;
            cout << this->name << " is filled with violence, and thrusts their weapon "
            << "into the heart of " << target->name << " for a CRITICAL STRIKE dealing "
            << damage << " points of damage.\n\n";
            return target->takeDamage(damage);
        }
    }
}

bool Player::takeDamage(int damage){
    if (this->armor > 0){
        damage = damage - armor;
        if (damage < 0)
            damage = 0;
        cout << this->name << "'s armor reduces damage by " << armor << " points.\n\n";
    }
    this->health -= damage;
    if (this->health <= 0)
        return true;
    else
        return false;
}

bool Player::processEffects(bool &loseTurn){
    // Process all effects
    for (int i = 0; i < this->effects.size(); i++){
        // Poison
        if(this->effects[i].type == "Poison"){
            cout << this->name << " takes " << this->effects[i].damage
                 << " points of poison damage.\n\n";
            this->health -= this->effects[i].damage;
            this->effects[i].duration -= 1;
        }

        // Stun
        if(this->effects[i].type == "Stun"){
            cout << this->name << " is stunned and cannot react.\n\n";
            loseTurn = true;
            this->effects[i].duration--;
        }
    }

    // Remove expired effects
    for (int i = 0; i < this->effects.size(); i++){
        if (this->effects[i].duration <= 0){
            for(int j = i; j < this->effects.size() - 1; j++) {
                this->effects[i] = this->effects[i + 1];
            }
            this->effects.pop_back();
            i--;
        }
    }

    // Determine if dead.
    if(this->health <= 0)
        return true;
    else
        return false;
}

void Player::die() {
    cout << this->name << " dies.\n\n";
}

string Player::status(){
    string result = this->name + "  Health: " + to_string(this->health)
        + "  " + this->resourceName + ": " + to_string(this->resource)
        + "  Armor: " + to_string(this->armor) + "  [";
    for (Effect effect : this->effects){
        result += " " + effect.type + " ";
    }
    return result + "]";
}














