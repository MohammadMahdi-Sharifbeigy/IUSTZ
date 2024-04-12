#ifndef ASSASSINATTACK_H
#define ASSASSINATTACK_H

#include <iostream>
#include "AttackStrategy.h"
#include "Character.h"
#include "Enemy.h"

class AssassinAttack : public AttackStrategy {
 public:
  AssassinAttack() : AttackStrategy(){};
  double attackEnemy(Character* currCharacter, Enemy* currEnemy){
  // Assassins have very high attack but low defense
  return (2* (currCharacter->getMaxHP() / currCharacter->getCurrentHP())
            * ( currCharacter->getAttack()/ currEnemy->get_enemy_def()));
}
  double defenseEnemy(Character* currCharacter, Enemy* currEnemy){
  // Assassins have low defense
  return ((currCharacter->getMaxHP() / currCharacter->getCurrentHP())
            * ( currCharacter->getDefense()  / currEnemy->get_enemy_atk()));
}

double attackOpponent(Human* currCharacter, Human* opponent){
  // Assassins have very high attack but low defense
  return (2.5 * (currCharacter->getMaxHP() / currCharacter->getCurrentHP())
            * ( currCharacter->getDefense()  / opponent->getDefense()));
}

double defenseOpponent(Human* currCharacter, Human* opponent){       
       // Assassins have low defense
  return (1.5 * (currCharacter->getMaxHP() / currCharacter->getCurrentHP())
              * ( currCharacter->getDefense()  / opponent->getDefense()));
}

};

#endif  // ASSASSINATTACK_H