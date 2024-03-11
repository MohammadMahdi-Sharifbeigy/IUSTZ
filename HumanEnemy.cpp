//
//  HumanEnemy.cpp
//  
//
//  Created by Lilia Rouhi on 12/21/1402 AP.
//

#include "HumanEnemy.hpp"
#include <HumanEnemy.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <random>


using namespace std;
using namespace HumanEnemy;


HumanEnemy(Human* human){
     chestArmor = nullptr;
     leggings = nullptr;
     weapon = nullptr;
     helmet = nullptr;
     this->name = "Human Enemy";
     this->role = "Enemy";
     this->age = human->getAge();
     coin = 0;
    srand(time(0));
    if ( human->getLevel() > 2){
        int n = (rand()%5) - 2;
        level = human->getLevel() + n;
        maxHP = human->getMaxHP() + (n*30);
        currHP = maxHP;
        maxXP = human-> getMaxXP() + (n*25);
        currXP = maxXP;
        attack = human->getAttack() + (10*n);
        defense = human->getDefense() + (n*5);
        stamin = human->getStamin() + (n*15);
        strenght = human->getStamin() + (n*2);
        endurance = human->getEndurance() + (2*n);
        accuracy = human->getAccuracy() + (2*n);
        pace = human->getPace() + (2*n);
        mind = human->getMind() + (2*n);
    }else if(human->getLevel() == 2){
        int n = (rand()%3) - 1;
        level = human->getLevel() + n;
        maxHP = human->getMaxHP() + (n*30);
        currHP = maxHP;
        maxXP = human-> getMaxXP() + (n*25);
        currXP = maxXP;
        attack = human->getAttack() + (10*n);
        defense = human->getDefense() + (n*5);
        stamin = human->getStamin() + (n*15);
        strenght = human->getStamin() + (n*2);
        endurance = human->getEndurance() + (2*n);
        accuracy = human->getAccuracy() + (2*n);
        pace = human->getPace() + (2*n);
        mind = human->getMind() + (2*n);
    }else{
        int n = (rand()%2) ;
        level = human->getLevel() + n;
        maxHP = human->getMaxHP() + (n*30);
        currHP = maxHP;
        maxXP = human-> getMaxXP() + (n*25);
        currXP = maxXP;
        attack = human->getAttack() + (10*n);
        defense = human->getDefense() + (n*5);
        stamin = human->getStamin() + (n*15);
        strenght = human->getStamin() + (n*2);
        endurance = human->getEndurance() + (2*n);
        accuracy = human->getAccuracy() + (2*n);
        pace = human->getPace() + (2*n);
        mind = human->getMind() + (2*n);
    }
}


virtual int attack_func (Character * currEnemy , Item* item) override {
    return 0;
}

virtual void takeDamage(int damage) override{
    
}
