#ifndef HUMANENEMYATTACK_H
#define HUMANENEMYATTACK_H
#include <iostream>
#include "AttackStrategy.h"
#include "Character.h"
#include "Enemy.h"

class HumanEnemyAttack : public AttackStrategy {
 public:
  HumanEnemyAttack() : AttackStrategy(){};
  virtual int attackCharacter(Character* currCharacter, Enemy* currEnemy) = 0;
  virtual int defenseCharacter(Character* currCharacter, Enemy* currEnemy) = 0;
};

#endif  // HUMANENEMYATTACK_H