#ifndef SUPERHEROATTACK_H
#define SUPERHEROATTACK_H

#include <iostream>
#include "AttackStrategy.h"
#include "Character.h"
#include "Enemy.h"

class SuperHeroAttack : public AttackStrategy {
 public:
  SuperHeroAttack() : AttackStrategy(){};
  double attackEnemy(Character* currCharacter, Enemy* currEnemy) {
    // Superheroes have high attack
    return (2 * currCharacter->getLevel() * (currCharacter->getMaxHP() 
          /currCharacter->getCurrentHP()) * (currCharacter->getAttack() / currEnemy->get_enemy_def()));
  }

  double defenseEnemy(Character* currCharacter, Enemy* currEnemy) {
    // Superheroes have balanced defense
    return (currCharacter->getLevel() * (currCharacter->getMaxHP()
           /currCharacter->getCurrentHP()) * (currCharacter->getDefense() / currEnemy->get_enemy_atk()));
  }
};

#endif  // SUPERHEROATTACK_H
