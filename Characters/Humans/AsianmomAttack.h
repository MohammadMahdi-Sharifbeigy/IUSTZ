#ifndef ASIANMOMATTACK_H
#define ASIANMOMATTACK_H

#include <iostream>
#include "../AttackStrategy.h"
#include "../Character.h"
#include "../Enemies/Enemy.h"

class AsianmomAttack : public AttackStrategy {
 public:
  AsianmomAttack() : AttackStrategy(){};
  double attackEnemy(Character* currCharacter, Enemy* currEnemy) {
    // Asian Moms have moderate attack but high wisdom
    Human* human = dynamic_cast<Human*>(currCharacter);
    if (human) {
      return (human->getLevel() * human->getMind() * (human->getAttack()  / currEnemy->get_enemy_def() - 1));
    }
    return 0;  // or some default value
  }
  double defenseEnemy(Character* currCharacter, Enemy* currEnemy) {
    // Asian Moms have high defense due to their wisdom
    Human* human = dynamic_cast<Human*>(currCharacter);
    if (human) {
      return (human->getLevel() * human->getMind() * ( human->getDefense()  / currEnemy->get_enemy_atk() - 1));
    }
    return 0;  // or some default value
  }
};

#endif  // ASIANMOMATTACK_H
