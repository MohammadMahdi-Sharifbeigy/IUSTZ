#ifndef ASSASSINATTACK_H
#define ASSASSINATTACK_H

#include <iostream>
#include "AttackStrategy.h"
#include "Character.h"
#include "Enemy.h"

class AssassinAttack : public AttackStrategy {
 public:
  AssassinAttack() : AttackStrategy(){};
  double attackEnemy(Character* currCharacter, Enemy* currEnemy) {
  // Assassins have very high attack but low defense
  return (3 * currCharacter->getLevel() * currCharacter->getAttack() * currCharacter->getMaxHP() 
         /currCharacter->getCurrentHP()) / currEnemy->get_enemy_def();
}
  double defenseEnemy(Character* currCharacter, Enemy* currEnemy) {
  // Assassins have low defense
  return (0.5 * currCharacter->getLevel() * currCharacter->getDefense() * currCharacter->getMaxHP() 
         /currCharacter->getCurrentHP()) / currEnemy->get_enemy_atk();
}
};

#endif  // ASSASSINATTACK_H
