#ifndef WIZARDATTACK_H
#define WIZARDATTACK_H

#include <iostream>
#include "AttackStrategy.h"
#include "Character.h"
#include "Enemy.h"

class WizardAttack : public AttackStrategy {
 public:
  WizardAttack() : AttackStrategy(){};
  double attackEnemy(Character* currCharacter, Enemy* currEnemy) {
    // Wizards have high attack due to their magic
    Human* human = dynamic_cast<Human*>(currCharacter);
    if (human) {
      return (1.5 * (human->getMind() / human->getStrength ()) * ( human->getMaxHP() / human->getCurrentHP())
                * (human->getAttack() / currEnemy->get_enemy_def()));
    }
    return 0;  // or some default value
  }
    double defenseEnemy(Character* currCharacter, Enemy* currEnemy) {
      // Wizards have high defense due to their magic
      Human* human = dynamic_cast<Human*>(currCharacter);
      if (human) {
        return (1 * (human->getMind() / human->getStrength ()) * (human->getMaxHP() / human->getCurrentHP()) 
                  * ( human->getDefense()/currEnemy->get_enemy_atk()));
      }
      return 0;  // or some default value
    }

    double attackOpponent(Human* currCharacter, Human* opponent) {
      // Wizards have high attack due to their magic
      return (2 * ( currCharacter->getMind() / currCharacter->getStrength ()) * (currCharacter->getMaxHP() / currCharacter->getCurrentHP())
                * ( currCharacter->getAttack() / opponent->getDefense()));
    }

    double defenseOpponent(Human* currCharacter, Human* opponent) {
      // Wizards have high defense due to their magic
      return (1.5 * ( currCharacter->getMind() / currCharacter->getStrength ()) * (currCharacter->getMaxHP() / currCharacter->getCurrentHP()) 
                  * ( currCharacter->getDefense() / opponent->getAttack()));
    }
};

#endif  // WIZARDATTACK_H
