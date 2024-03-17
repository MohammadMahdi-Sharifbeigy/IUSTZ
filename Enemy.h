#ifndef __ENEMY_H__
#define __ENEMY_H__
#include <stdlib.h>
#include <string>
#include <time.h>
#include <cstdlib>
#include <random>
#include "Character.h"
#include "Human.h"
#include "CharacterType.h"

using namespace std;

int getRandomNumber(int a, int b)
{
    random_device rd;
    mt19937 eng(rd());
    uniform_int_distribution<> distr(a, b);

    return distr(eng);
}

class Enemy : public Character
{
public:
    Enemy(){}
    Enemy(int characterLevel)
    {
        hp = getRandomNumber(characterLevel, characterLevel + 10);
        attack;
        defense;
        level;
        giveExp = level * 10 * attack / defense;
    }

protected:
    int hp;
    int attack;
    int defense;
    int level;
    int giveExp;
    characterType role;

public:
    virtual int attackChar(double charDefense) = 0;
    
    virtual void takeDamage() override;

    int get_enemy_hp()
    {
        return hp;
    }

    int get_enemy_atk()
    {
        return attack;
    }

    int get_enemy_def()
    {
        return defense;
    }

    int get_enemy_lvl()
    {
        return level;
    }

    int get_enemy_exp()
    {
        return giveExp;
    }

    void set_enemy_hp(int value)
    {
        hp -= value;
    }
    characterType getcharType() const
    {
        return role;
    }
    characterType setRole(characterType newRole)
    {
        return newRole;
    }
};

#endif //__Enemy_H__