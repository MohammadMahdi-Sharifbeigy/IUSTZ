//
//  Character.cpp
//  
//
//  Created by Lilia Rouhi on 12/21/1402 AP.
//

#include "Character.hpp"
#include <Character.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <random>


using namespace std;
using namespace Character;


Character() = default;

virtual string NameMaker(){
    return" ";
}

string getName(){
    return name;
}

void setName(string name){
    this->name = name;
}

int getCurrHP (){
    return currHP;
}

void setCurrHP (int currHp){
    this->currHP = currHp;
}

int getMaxHP (){
    return maxHP;
}

void setMaxHP (int maxHP){
    this->maxHP = maxHP;
}

int getLevel (){
    return level;
}

void setLevel(int level){
    this->level = level;
}

string getRole(){
    return  role;
}

void setRole(string role){
    this->role = role;
}

int getAttack (){
    return attack;
}

void setAttack (int attack){
    this->attack = attack;
}

int getDefense (){
    return defense;
}

void setDefense (int defense){
    this->defense = defense;
}
