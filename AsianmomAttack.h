#ifndef ASIANMOMATTACK_H
#define ASIANMOMATTACK_H

#include <iostream>
#include "AttackStrategy.h"
#include "Character.h"
#include "Enemy.h"

class AsianmomAttack : public AttackStrategy {
 public:
  AsianmomAttack() : AttackStrategy(){};
  double attackEnemy(Character* currCharacter, Enemy* currEnemy) {
    return ((((((2 * currCharacter->getLevel()) / 5) + 2) * 35 *
              currCharacter->getAttack()) *
              currCharacter->getMaxHP() / currCharacter->getCurrentHP()) /
              currCharacter->getDefense() * 5) + 2;
  }
  double defenseEnemy(Character* currCharacter, Enemy* currEnemy) {
    return ((((((2 * currCharacter->getLevel()) / 5) + 2) * 35 *
              currCharacter->getDefense()) *
              currCharacter->getMaxHP() / currCharacter->getCurrentHP()) /
              currEnemy->get_enemy_atk() * 5) + 2;
  }
};

#endif  // SNIPERATTACK_H
