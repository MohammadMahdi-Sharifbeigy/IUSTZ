//
//  Human.cpp
//  
//
//  Created by Lilia Rouhi on 12/21/1402 AP.
//

#include "Human.hpp"
#include <Human.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <random>


using namespace std;
using namespace Human;




virtual int attack_func(Human* curenemy , Item* item) = 0;
virtual int attack_func(Character* curenemy , Item* item) = 0;
virtual void takeDamage(int damage)=0;
Human() = default;
Human(string name,string role , int age) {
   // attackMethod = new PaladinAttack();
    chestArmor = nullptr;
    leggings = nullptr;
    weapon = nullptr;
    helmet = nullptr;
    this->name = name;
    this->role = role;
    this->age = age;
    maxHP = 100;
    currHP = 100;
    attack = 5;
    defense = 5;
    level = 1;
    currXP = 0;
    maxXP = 100;
    stamin = 100;
    strenght = 1;
    endurance = 1;
    accuracy = 1;
    pace = 1;
    mind = 1;
    coin = 50;
}


virtual string NameMaker() override{
    return" ";
}


void firearm_ability(){
    
}

void coldweapon_ability(){
    
}

void addEquipments(Item* newEquipment){
    equipment.push_back(newEquipment);
}

void addConsumables(Item* newConsumable){
    consumables.push_back(newConsumable);
}

void showEquipments(){
    if(equipment.size()> 0){
        for(int i=0; i< equipment.size(); i++){
            cout<<i+1<<". "<<equipment[i]<<endl;
        }
    }else{
        cout<<"You have no equipments"<<endl;
    }
}

void showConsumables(){
    if(consumables.size()> 0){
        for(int i=0; i< consumables.size(); i++){
            cout<<i+1<<". "<<consumables[i]<<endl;
        }
    }else{
        cout<<"You have no consumables"<<endl;
    }
}

virtual void levelUp() = 0;

int getAge(){
    return age;
}

void setName(int age){
    this->age = age;
}

int getCurrXP (){
    return currXP;
}

void setCurrXP (int currXP){
    this->currXP = currXP;
}

int getMaxXP (){
    return maxXP;
}

void setMaxXP (int maxXP){
    this->maxXP = maxXP;
}

double getStamin(){
    return  stamin;
}

void setStamin(double stamin){
    this->stamin = stamin;
}

double getStrenght (){
    return strenght;
}

void setStrenght (double strenght){
    this->strenght = strenght;
}

double getEndurance (){
    return endurance;
}

void setEndurance (double endurance){
    this->endurance = endurance;
}


double getAccuracy(){
    return  accuracy;
}

void setAccuracy(double accuracy){
    this->accuracy = accuracy;
}

double getPace (){
    return pace;
}

void setPace (double pace){
    this->pace = pace;
}

double getMind (){
    return mind;
}

void setMind (double mind){
    this->mind = mind;
}

int getCoin(){
    return coin;
}

void setCoin(int coin){
    this->coin = coin;
}

Item* getChestArmor (){
    return chestArmor;
}

void setChestArmor (Item* chestArmor){
    this->chestArmor = chestArmor;
}

Item* getWeapon (){
    return weapon;
}

void setWeapon (Item* weapon){
    this->weapon = weapon;
}

Item* getLeggings (){
    return leggings;
}

void setLeggings (Item* leggings){
    this->leggings = leggings;
}

Item* getHelmet (){
    return helmet;
}

void setHelmet (Item* helmet){
    this->helmet = helmet;
}
