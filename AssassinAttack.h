#ifndef ASSASSINATTACK_H
#define ASSASSINATTACK_H

#include <iostream>
#include "Character.h"
#include "Enemy.h"
#include "AttackStrategy.h"

class AssassinAttack : public AttackStrategy
{
public:
    AssassinAttack() : AttackStrategy(){};
    int attackEnemy(Character *currCharacter, Enemy *currEnemy)
    {
        return abs(((((((2 * currCharacter->getLevel()) / 5) + 2) * 35 * currCharacter->getAttack()) * currCharacter->getMaxHP() / currCharacter->getCurrentHP()) / currCharacter->getDefense() * 5) + 2);
    }
};

#endif // ASSASSINATTACK_H
