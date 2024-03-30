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
    // Asian Moms have moderate attack but high wisdom
    Human* human = dynamic_cast<Human*>(currCharacter);
    if (human) {
      return (human->getLevel() * human->getMind() * human->getMaxHP() / human->getCurrentHP()) /currEnemy->get_enemy_def();
    }
    return 0;  // or some default value
  }
  double defenseEnemy(Character* currCharacter, Enemy* currEnemy) {
    // Asian Moms have high defense due to their wisdom
    Human* human = dynamic_cast<Human*>(currCharacter);
    if (human) {
      return (human->getLevel() * human->getMind() * human->getMaxHP() / human->getCurrentHP()) / currEnemy->get_enemy_atk();
    }
    return 0;  // or some default value
  }
};

#endif  // SNIPERATTACK_H
