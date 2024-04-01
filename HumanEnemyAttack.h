#ifndef HUMANENEMYATTACK_H
#define HUMANENEMYATTACK_H
#include <iostream>
#include "AttackStrategy.h"
#include "Character.h"
#include "Enemy.h"
#include "CharacterType.h"

class HumanEnemyAttack : public AttackStrategy {
public:
    HumanEnemyAttack() : AttackStrategy() {};

  double attackEnemy(Character* currCharacter, Enemy* currEnemy) override {
    // Assuming this character has a high attack but low defense like an Assassin
    return (3 * (currCharacter->getAttack() / currCharacter->getLevel()) * 
           (currCharacter->getMaxHP() / currCharacter->getCurrentHP())*
           (currCharacter->getAttack() / currEnemy->get_enemy_def()));
  }

  double defenseEnemy(Character* currCharacter, Enemy* currEnemy) override {
    // Assuming this character has low defense
    return (0.5 * (currCharacter->getDefense() / currCharacter->getLevel()) * 
           (currCharacter->getMaxHP() / currCharacter->getCurrentHP()) * 
           (currCharacter->getDefense() / currEnemy->get_enemy_atk()));
  }
    // Define functions for attack and defense modifiers
    double cyborgVsWizardAttack(Character* currHuman, Enemy* currCharacter) {
        // Return a smaller number for attack
        return 0.75 * attackEnemy(currHuman, currCharacter);
    }

    double cyborgVsWizardDefense(Character* currHuman, Enemy* currCharacter) {
        // Return a bigger number for defense
        return 1.25 * defenseEnemy(currHuman, currCharacter);
    }

    // Define a structure to represent the FSM state
    struct FSMState {
        double (HumanEnemyAttack::*attackModifier)(Character*, Enemy*);
        double (HumanEnemyAttack::*defenseModifier)(Character*, Enemy*);
    };

    // Initialize FSM states for each character type
    FSMState fsmStates[7] = {
        // ... other character states ...
      fsmStates[CYBORG] = {&HumanEnemyAttack::cyborgVsWizardAttack, &HumanEnemyAttack::cyborgVsWizardDefense}
        // ... other character states ...
    };

    // Modify the attack and defense values based on the FSM state
    std::pair<double, double> applyFSM(characterType currHumanRole, Character* currHuman, Enemy* currCharacter) {
    FSMState state = fsmStates[currHumanRole];
  
    double attack = (this->*state.attackModifier)(currHuman, currCharacter);
    double defense = (this->*state.defenseModifier)(currHuman, currCharacter);

    // modify the attack and defense based on additional game logic here
    // ...

    // Return the modified values as a pair
    return std::make_pair(attack, defense);
    }

};

#endif  // HUMANENEMYATTACK_H
