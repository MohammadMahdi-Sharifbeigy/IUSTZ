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
  return (3 *currCharacter->getLevel() * currCharacter->getDefense() * (currCharacter->getMaxHP() 
            /currCharacter->getCurrentHP()) * ( currCharacter->getDefense()  / currEnemy->get_enemy_atk()));
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

#endif  // PALADINATTACK_H
