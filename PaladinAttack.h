#ifndef PALADINATTACK_H
#define PALADINATTACK_H

#include <iostream>
#include "Character.h"
#include "Enemy.h"
#include "AttackStrategy.h"

class PaladinAttack : public AttackStrategy
{
public:
    PaladinAttack() : AttackStrategy(){};
    int attackEnemy(Character *currCharacter, Enemy *currEnemy)
    {
        return abs(((((((2 * currCharacter->getLevel()) / 5) + 2) * 35 * currCharacter->getAttack()) * currCharacter->getMaxHP() / currCharacter->getCurrentHP()) / currCharacter->getDefense() * 5) + 2);
    }
};

#endif // PALADINATTACK_H
