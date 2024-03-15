#ifndef HUMAN_H
#define HUMAN_H

#include "Character.h"

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
    // vector<Items *> inventory;
    virtual void takeDamage(int damage);

public:
    Human() = default;
    Human(const std::string &name, double hp, double attack, double defense, characterType role)
    {
        this->name = name;
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

    // Items Functions

    /*
    void showEquipments();
    void showConsumables();

    void addInventory(Items *item)
    {
        inventory.push_back(item);
    }

    void removeInventory(int index)
    {
        if (index < this->inventorySize())
        {
            inventory.erase(inventory.begin() + index);
        }
    }

    int inventorySize()
    {
        return inventory.size();
    }

    Items *itemssAt(int index)
    {
        if (this->inventorySize())
        {
            return inventory.at(index);
        }
        return nullptr;
    }

    Items *getArmor()
    {
        return Armor;
    }
    Items *getWeapon()
    {
        return weapon;
    }
    */
};

#endif /* Human_h */
