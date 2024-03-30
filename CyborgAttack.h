#ifndef CYBORGATTACK_H
#define CYBORGATTACK_H

#include <iostream>
#include "AttackStrategy.h"
#include "Character.h"
#include "Enemy.h"

class CyborgAttack : public AttackStrategy {
 public:
  CyborgAttack() : AttackStrategy(){};
  double attackEnemy(Character* currCharacter, Enemy* currEnemy) {
    // Cyborgs have high attack due to their mechanical nature
    return (4 * currCharacter->getLevel() * currCharacter->getAttack() * currCharacter->getMaxHP() / currCharacter->getCurrentHP())
              / currEnemy->get_enemy_def();
  }
  double defenseEnemy(Character* currCharacter, Enemy* currEnemy) {
    // Cyborgs have high defense due to their armored body
    return (3 * currCharacter->getLevel() * currCharacter->getDefense() * currCharacter->getMaxHP() / currCharacter->getCurrentHP())
              / currEnemy->get_enemy_atk();
  }
};

#endif  // CYBORGATTACK_H
