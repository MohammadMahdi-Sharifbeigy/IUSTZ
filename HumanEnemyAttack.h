#ifndef HUMANENEMYATTACK_H
#define HUMANENEMYATTACK_H
#include <iostream>
#include <utility>
#include "AttackStrategy.h"
#include "Character.h"
#include "Enemy.h"
#include "CharacterType.h"

// Define enum for attack types
enum AttackType {
  ATTACK_PALADIN,
  ATTACK_SUPERHERO,
  ATTACK_ASSASSIN,
  ATTACK_ASIANMOM,
  ATTACK_CYBORG,
  ATTACK_SNIPER,
  ATTACK_WIZARD,
  ATTACK_DEFAULT
};

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

  // Define a structure to hold attack and defense modifiers
  struct Modifiers {
      double attackModifier;
      double defenseModifier;
  };

  // Method to map a character's role to the corresponding AttackType
  AttackType getAttackTypeForRole(characterType role) {
      switch (role) {
          case WIZARD:
              return ATTACK_WIZARD;
          case SUPERHERO:
              return ATTACK_SUPERHERO;
          case ASIANMOM:
            return ATTACK_ASIANMOM;
          case PALADIN:
              return ATTACK_PALADIN;
          case SNIPER:
              return ATTACK_SNIPER;
          case CYBORG:
              return ATTACK_CYBORG;
          case ASSASSIN:
              return ATTACK_ASSASSIN;
          // Add cases for other roles as needed
          default:
            return ATTACK_DEFAULT; 
        }
    }
  // Function to calculate attack and defense modifiers
  Modifiers calculateModifiers(Character* currHuman, Enemy* currCharacter, AttackType attackType) {
    Modifiers modifiers;
    switch (attackType) {
        case ATTACK_PALADIN:
          modifiers.attackModifier = 0.8;
          modifiers.defenseModifier = 1.1;
          break;
        case ATTACK_SUPERHERO:
          modifiers.attackModifier = 0.8;
          modifiers.defenseModifier = 0.9;
          break;
        case ATTACK_CYBORG:
          modifiers.attackModifier = 0.9;
          modifiers.defenseModifier = 1.15;
            break;
        case ATTACK_ASSASSIN:
          modifiers.attackModifier = 0.8;
          modifiers.defenseModifier = 1.2;
          break;
        case ATTACK_WIZARD:
          modifiers.attackModifier = 0.75;
          modifiers.defenseModifier = 1.25;
          break;
        case ATTACK_ASIANMOM:
          modifiers.attackModifier = 1.2;
          modifiers.defenseModifier = 0.95;
          break;
          case ATTACK_SNIPER:
          modifiers.attackModifier = 1.2;
          modifiers.defenseModifier = 0.75;
          break;
        default:
          modifiers.attackModifier = 1.0;
          modifiers.defenseModifier = 1.0;
          break;
  }
  modifiers.attackModifier *= attackEnemy(currHuman, currCharacter);
  modifiers.defenseModifier *= defenseEnemy(currHuman, currCharacter);
  return modifiers;
}
    // Define a structure to represent the FSM state
    struct FSMState {
        Modifiers (HumanEnemyAttack::*calculate)(Character*, Enemy*, AttackType);
        AttackType type;
    };

    // Initialize FSM states for each character type
    FSMState fsmStates[7] = {
        // Cyborg vs Wizard
        {&HumanEnemyAttack::calculateModifiers, ATTACK_WIZARD},
        // Paladin vs SuperHero
        {&HumanEnemyAttack::calculateModifiers, ATTACK_SUPERHERO},
        // SuperHero vs AsianMom
        {&HumanEnemyAttack::calculateModifiers, ATTACK_ASIANMOM},
        // Assassin vs Paladin
        {&HumanEnemyAttack::calculateModifiers, ATTACK_PALADIN},
        // AsianMom vs Sniper
        {&HumanEnemyAttack::calculateModifiers, ATTACK_SNIPER},
        // Sniper vs Cyborg
        {&HumanEnemyAttack::calculateModifiers, ATTACK_CYBORG},
        // Wizard vs Assassin
        {&HumanEnemyAttack::calculateModifiers, ATTACK_ASSASSIN}
    };

    std::pair<double, double> applyFSM(characterType currHumanRole, Character* currHuman, Enemy* currCharacter, AttackType attackType) {
    FSMState state = fsmStates[currHumanRole];
    Modifiers modifiers = (this->*state.calculate)(currHuman, currCharacter, attackType);

    double attack = modifiers.attackModifier;
    double defense = modifiers.defenseModifier;

    return std::make_pair(attack, defense);
  }
};

#endif  // HUMANENEMYATTACK_H
