#ifndef PALADINATTACK_H
#define PALADINATTACK_H

#include <iostream>
#include "AttackStrategy.h"
#include "Character.h"
#include "Enemy.h"

class PaladinAttack : public AttackStrategy {
 public:
  PaladinAttack() : AttackStrategy(){};
  double attackEnemy(Character* currCharacter, Enemy* currEnemy) {
  // Paladins have a balanced attack strategy
  return (currCharacter->getLevel() * currCharacter->getAttack() * (currCharacter->getMaxHP()
         /currCharacter->getCurrentHP()) * ( currCharacter->getAttack() / currEnemy->get_enemy_def()));
  }

  double defenseEnemy(Character* currCharacter, Enemy* currEnemy) {
  // Paladins have high defense
  return (1.5 *currCharacter->getLevel() * currCharacter->getDefense() * (currCharacter->getMaxHP() 
            /currCharacter->getCurrentHP()) * ( currCharacter->getDefense()  / currEnemy->get_enemy_atk()));
  }

    double attackOpponent(Human* currCharacter, Human* opponent) {
  // Paladins have a balanced attack strategy
  return (1.25 * currCharacter->getLevel() * currCharacter->getAttack() * (currCharacter->getMaxHP()
         /currCharacter->getCurrentHP()) * ( currCharacter->getAttack() / opponent->getDefense()));
  }

  double defenseOpponent(Human* currCharacter, Human* opponent) {
    // Paladins have high defense
    return (2 *currCharacter->getLevel() * currCharacter->getDefense() * (currCharacter->getMaxHP() 
            /currCharacter->getCurrentHP()) * ( currCharacter->getDefense()  / opponent->getDefense()));
  }
  
};

#endif  // PALADINATTACK_H
