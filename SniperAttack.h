#ifndef SNIPERATTACK_H
#define SNIPERATTACK_H

#include <iostream>
#include "AttackStrategy.h"
#include "Character.h"
#include "Enemy.h"

class SniperAttack : public AttackStrategy {
 public:
  SniperAttack() : AttackStrategy(){};
  double attackEnemy(Character* currCharacter, Enemy* currEnemy) {
    // Snipers have very high attack due to precision strikes
    Human* human = dynamic_cast<Human*>(currCharacter);
    if (human) {
      return (1.5 * (human->getLevel() * human->getAccuracy() * human->getAttack()) *( human->getMaxHP() / human->getCurrentHP())
                * ( currCharacter->getAttack()  / currEnemy->get_enemy_def()) + 1);
    }
    return 0;  // or some default value
  }
  double defenseEnemy(Character* currCharacter, Enemy* currEnemy) {
    // Snipers have low defense
    Human* human = dynamic_cast<Human*>(currCharacter);
    if (human) {
      return (0.75 * (human->getLevel() * human->getDefense()) * (human->getMaxHP() / human->getCurrentHP()) 
                  * ( currCharacter->getDefense()  / currEnemy->get_enemy_atk()));
    }
    return 0;  // or some default value
  }

  double attackOpponent(Human* currCharacter, Human* opponent) {
    // Snipers have very high attack due to precision strikes
    return (2 * (currCharacter->getLevel() * currCharacter->getAccuracy() * currCharacter->getAttack()) * (currCharacter->getMaxHP() / currCharacter->getCurrentHP())
              * ( currCharacter->getAttack() / opponent->getDefense()) + 1);
  }

  double defenseOpponent(Human* currCharacter, Human* opponent) {
    // Snipers have low defense
    return (1 * (currCharacter->getLevel() * currCharacter->getDefense()) * (currCharacter->getMaxHP() / currCharacter->getCurrentHP())
              * ( currCharacter->getDefense() / opponent->getAttack()));
  }
};

#endif  // SNIPERATTACK_H
