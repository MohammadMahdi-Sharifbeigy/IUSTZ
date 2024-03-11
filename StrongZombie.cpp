//
//  StrongZombie.cpp
//  
//
//  Created by Lilia Rouhi on 12/21/1402 AP.
//

#include "StrongZombie.hpp"
#include <StrongZombie.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <random>


using namespace std;
using namespace StrongZombie;



StrongZombie(Human* human){
    name = "Strong Zombie";
    role = "Enemy";
    srand(time(0));
        int n = (rand()%3)+1;
        level = (human->getLevel()) + n;
        maxHP = human->getMaxHP() + (n*30);
        currHP = maxHP;
        attack = (human->getAttack()) + (n*10);
        defense = (human->getDefense()) + (n*5);
}

virtual int attack_func(Human* curenemy){
    return 0;
}

virtual void takeDamage(){
    
}
