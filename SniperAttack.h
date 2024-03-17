#ifndef SNIPERATTACK_H
#define SNIPERATTACK_H

#include <iostream>
#include "AttackStrategy.h"
#include "Character.h"
#include "Enemy.h"

class SniperAttack : public AttackStrategy {
 public:
  SniperAttack() : AttackStrategy(){};
  double attackEnemy(Character* currCharacter, Enemy* currEnemy) {
    return abs(((((((2 * currCharacter->getLevel()) / 5) + 2) * 35 *
                  currCharacter->getAttack()) *
                 currCharacter->getMaxHP() / currCharacter->getCurrentHP()) /
                currCharacter->getDefense() * 5) +
               2);
  }
  double defenseEnemy(Character* currCharacter, Enemy* currEnemy) {
    return abs(((((((2 * currCharacter->getLevel()) / 5) + 2) * 35 *
                  currCharacter->getDefense()) *
                 currCharacter->getMaxHP() / currCharacter->getCurrentHP()) /
                currEnemy->get_enemy_atk() * 5) +
               2);
  }
};

#endif  // SNIPERATTACK_H
