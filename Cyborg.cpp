//
//  Cyborg.cpp
//  
//
//  Created by Lilia Rouhi on 12/21/1402 AP.
//

#include "Cyborg.hpp"
#include <Cyborg.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <random>


using namespace std;
using namespace Cyborg;


Cyborg(string name , int age) {
   // attackMethod = new PaladinAttack();
    chestArmor = nullptr;
    leggings = nullptr;
    weapon = nullptr;
    helmet = nullptr;
    this->name = name;
    this->role = "Cyborg";
    this->age = age;
    maxHP = 100;
    currHP = 100;
    attack = 10;
    defense = 5;
    level = 1;
    currXP = 0;
    maxXP = 100;
    stamin = 100;
    strenght = 1;
    endurance = 3;
    accuracy = 1;
    pace = 1;
    mind = 1;
    coin = 50;
}

virtual int attack_func (Human * currEnemy , Item* item) override {
    return 0;
}

virtual int attack_func (Character * currEnemy , Item* item) override {
    return 0;
}

virtual void takeDamage(int damage) override{
    
}

virtual void levelUp() override {
    while (currXP >= maxXP) {
        cout << "You have levled up!" << endl;
        maxHP += 30;
        attack += 10;
        defense += 5;
        level += 1;
        stamin += 15;
        strenght += 2;
        endurance += 3;
        accuracy += 2;
        pace += 2;
        mind += 2;
        currXP = currXP - maxXP;
    maxXP += 25;
        cout<<"Your level is "<<level<<" now!"<<endl;
    }
}
