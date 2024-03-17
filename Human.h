#ifndef HUMAN_H
#define HUMAN_H

#include "Character.h"
#include "Item.h"

using namespace std;



class Human : public Character
{
protected:
    int age;
    int maxXP;
    int currXP;
    double stamina;
    double strength;
    double endurance;
    double accuracy;
    double pace;
    double mind;
    int coin;
    Item* armor;
    Item* weapon;
    vector<Item *> inventory;
public:
    Human() = default;
    Human(const std::string &name,int age, double hp, double attack, double defense, characterType role)
    {
        this->name = name;
        this->age = age;
        this->maxHP = hp;
        this->currHP = hp;
        this->attack = attack;
        this->defense = defense;
        this->role = role;
        this->level = 1;
        this->currXP = 0;
        this->maxXP = 100;
    };
    virtual void performAttack(Character &target) = 0;
    virtual void performDefense(Enemy &attacker) = 0;
    virtual std::string NameMaker() override;
    virtual void levelUp();
    virtual void takeDamage() override;
    int getAge();
    void setName(int age);
    int getCurrXP();
    void setCurrXP(int currXP);
    int getMaxXP();
    void setMaxXP(int maxXP);
    double getStamina();
    void setStamina(double stamina);
    double getStrength();
    void setStrength(double strength);
    double getEndurance();
    void setEndurance(double endurance);
    double getAccuracy();
    void setAccuracy(double accuracy);
    double getPace();
    void setPace(double pace);
    double getMind();
    void setMind(double mind);
    int getCoin();
    void setCoin(int coin);
    // Item Functions
    
    Item *itemsAt(int index); 
    void showInventory();
    void addInventory(Item *item);
    void removeInventory(int index);
    void addInventory(Item *item , int count);
    void removeInventory(int index , int count);
    int inventorySize();
    Item *getArmor();
    Item *getWeapon();
    void setArmor(Item* aromor);
    void setWeapon(Item* weapon);
    Item *stringToItem(const std::string &line);
    
};

#endif /* Human_h */
