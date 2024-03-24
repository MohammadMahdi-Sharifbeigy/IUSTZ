#ifndef HUMANENEMYATTACK_H
#define HUMANENEMYATTACK_H
#include <iostream>
#include "AttackStrategy.h"
#include "Character.h"
#include "Enemy.h"

class HumanEnemyAttack : public AttackStrategy {
public:
  HumanEnemyAttack() : AttackStrategy() {};

  double attackEnemy(Character* currHuman, Enemy* currCharacter) {
    return ((((((2 * currCharacter->get_enemy_lvl()) / 5) + 2) * 35 *
              currCharacter->get_enemy_atk()) *
              currCharacter->getMaxHP() / currCharacter->get_enemy_hp()) /
              currCharacter->get_enemy_def() * 5) + 2;
  }
  double defenseEnemy(Character* currHuman, Enemy* currCharacter) {
    return ((((((2 * currCharacter->get_enemy_lvl()) / 5) + 2) * 35 *
              currCharacter->get_enemy_def()) *
              currCharacter->getMaxHP() / currCharacter->get_enemy_hp()) /
              currHuman->getAttack() * 5) + 2;
  }
};

#endif  // HUMANENEMYATTACK_H