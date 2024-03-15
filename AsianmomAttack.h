#ifndef ASIANMOMATTACK_H
#define ASIANMOMATTACK_H

#include <iostream>
#include "Character.h"
#include "Enemy.h"
#include "AttackStrategy.h"

class AsianmomAttack : public AttackStrategy
{
public:
    AsianmomAttack() : AttackStrategy(){};
    int attackEnemy(Character *currCharacter, Enemy *currEnemy)
    {
        return abs(((((((2 * currCharacter->getLevel()) / 5) + 2) * 35 * currCharacter->getAttack()) * currCharacter->getMaxHP() / currCharacter->getCurrentHP()) / currCharacter->getDefense() * 5) + 2);
    }
};

#endif // SNIPERATTACK_H
