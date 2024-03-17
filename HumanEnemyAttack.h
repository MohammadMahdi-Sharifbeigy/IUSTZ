#ifndef HUMANENEMYATTACK_H
#define HUMANENEMYATTACK_H
#include <iostream>
#include "Character.h"
#include "Enemy.h"
#include "AttackStrategy.h"

class HumanEnemyAttack : public AttackStrategy
{
public:
    HumanEnemyAttack() : AttackStrategy(){};
    virtual int attackCharacter(Character *currCharacter, Enemy *currEnemy) = 0;
    virtual int defenseCharacter(Character *currCharacter, Enemy *currEnemy) = 0;
};

#endif //HUMANENEMYATTACK_H