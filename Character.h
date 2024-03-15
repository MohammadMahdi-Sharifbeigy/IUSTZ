#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>
#include "AttackStrategy.h"
#include "CharacterType.h"

using namespace std;

class Character
{
protected:
    double maxHP;
    double currHP;
    int level;
    double attack;
    double defense;
    int maxXP;
    int currXP;
    std::string name;
    characterType role;

public:
    Character() {};
    Character(const std::string &name, double hp,int level, double attack, double defense, characterType role);
    ~Character();
    void setDefense(int def)
    {
        defense += def;
    }

    void setAttack(int atk)
    {
        attack += atk;
    }

    // Getters and Setters
    std::string getName() const;
    double getMaxHP() const;
    double getCurrentHP() const;
    double getAttack() const;
    double getDefense() const;
    int getMaxXP() const;
    int getCurrentXP() const;
    int getLevel() const;
    characterType getRole() const;

    virtual void levelUp() = 0;

    void setCurrentHP(double additionalHP)
    {
        if (additionalHP + currHP < this->getMaxHP())
        {
            currHP += additionalHP;
        }
        else
        {
            currHP = maxHP;
        }
    }
    void setCurrentHPAttack(double additionalHP)
    {
        currHP -= additionalHP;
    }
    void setCurrentXP(int XP)
    {
        currXP += XP;
        if (currXP >= maxXP)
        {
            this->levelUp();
        }
    }

    void setName(const std::string &newName);
    void setMaxHP(double newMaxHP);
    void setAttack(double newAttack);
    void setDefense(double newDefense);
    void setLevel(int level);
    void setRole(characterType Role);

    // Utility methods
    bool isAlive() const;
    void takeDamage(double amount);

    virtual std::string NameMaker();
};

#endif /* CHARACTER_H */
