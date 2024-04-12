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
    return (2.5 * currCharacter->getLevel() * (currCharacter->getMaxHP() / currCharacter->getCurrentHP())
              * ( currCharacter->getAttack()/ currEnemy->get_enemy_def()));
  }
  double defenseEnemy(Character* currCharacter, Enemy* currEnemy) {
    // Cyborgs have high defense due to their armored body
    return (currCharacter->getLevel() * (currCharacter->getMaxHP() / currCharacter->getCurrentHP())
              * ( currCharacter->getDefense()  / currEnemy->get_enemy_atk()));
  }
  double attackOpponent(Human* currCharacter, Human* opponent) {
    // Cyborgs have high attack due to their mechanical nature
    return (3.5 * currCharacter->getLevel() * (currCharacter->getMaxHP() / currCharacter->getCurrentHP())
              * ( currCharacter->getAttack() / opponent->getDefense()));
  }

  double defenseOpponent(Human* currCharacter, Human* opponent) {
    // Cyborgs have high defense due to their armored body
    return (2.5 * currCharacter->getLevel() * (currCharacter->getMaxHP() / currCharacter->getCurrentHP())
              * ( currCharacter->getDefense() / opponent->getAttack()));
  } 
};

#endif  // CYBORGATTACK_H
