//
//  WeakZombie.cpp
//  
//
//  Created by Lilia Rouhi on 12/21/1402 AP.
//

#include "WeakZombie.hpp"
#include <WeakZombie.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <random>


using namespace std;
using namespace WeakZombie;





WeakZombie(Human* human){
        name = "Weak Zombie";
        role = "Enemy";
        srand(time(0));
        if(human->getLevel() > 2){
            int n = (rand()%3)-2;
            maxHP = human->getMaxHP() + (n*30);
            currHP = maxHP;
            level = (human->getLevel()) + n;
            attack = (human->getAttack()) + (n*10);
            defense = (human->getDefense()) + (n*5);
        }else if(human->getLevel() == 2){
            int n = (rand()%2)-1;
            maxHP = human->getMaxHP() + (n*30);
            currHP = maxHP;
            level = (human->getLevel()) + n;
            attack = (human->getAttack()) + (n*10);
            defense = (human->getDefense()) + (n*5);
        }else{
            maxHP = human->getMaxHP();
            currHP = maxHP;
            level = (human->getLevel()) ;
            attack = (human->getAttack()) ;
            defense = (human->getDefense());
    }
                }
    

virtual int attack_func(Human* curenemy){
        return 0;
}
    

virtual void takeDamage(){
        
}
    
