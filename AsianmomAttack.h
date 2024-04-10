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

  double attackOpponent(Human* currCharacter, Human* opponent) {
    // Asian Moms have moderate attack but high wisdom
    return (currCharacter->getLevel() * currCharacter->getMind() * (currCharacter->getAttack() / opponent->getDefense() - 1));
  }

  double defenseOpponent(Human* currCharacter, Human* opponent) {
    // Asian Moms have high defense due to their wisdom
    return (currCharacter->getLevel() * currCharacter->getMind() * (currCharacter->getDefense() / opponent->getAttack() - 1));
  }
};

#endif  // ASIANMOMATTACK_H
