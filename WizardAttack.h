#ifndef WIZARDATTACK_H
#define WIZARDATTACK_H

#include <iostream>
#include "Character.h"
#include "Enemy.h"
#include "AttackStrategy.h"

class WizardAttack : public AttackStrategy
{
public:
    WizardAttack() : AttackStrategy(){};
    double attackEnemy(Character *currCharacter, Enemy *currEnemy)
    {
        return abs(((((((2 * currCharacter->getLevel()) / 5) + 2) * 35 * currCharacter->getAttack()) * currCharacter->getMaxHP() / currCharacter->getCurrentHP()) / currCharacter->getDefense() * 5) + 2);
    }
    double defenseEnemy(Character *currCharacter, Enemy *currEnemy)
    {
        return abs(((((((2 * currCharacter->getLevel()) / 5) + 2) * 35 * currCharacter->getDefense()) * currCharacter->getMaxHP() / currCharacter->getCurrentHP()) / currEnemy->get_enemy_atk() * 5) + 2);
    }
};

#endif // WIZARDATTACK_H
