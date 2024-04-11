#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>
#include "AttackStrategy.h"
#include "CharacterType.h"

using namespace std;

class Character {
 protected:
  string name;
  double currHP;
  double maxHP;
  int level;
  characterType role;
  double attack;
  double defense;

 public:
  Character(){};
  Character(const string& name,
            double hp,
            int level,
            double attack,
            double defense,
            characterType role);
  ~Character();
  void setDefense(int def) { defense += def; }

  void setAttack(int atk) { attack += atk; }

  // Getters and Setters
  string getName() const;
  double getMaxHP() const;
  double getCurrentHP() const;
  double getAttack() const;
  double getDefense() const;
  int getLevel() const;
  characterType getRole() const;

  virtual void levelUp() = 0;

  void setCurrentHP(double additionalHP) {
    if (additionalHP + currHP < this->getMaxHP()) {
      currHP += additionalHP;
    } else {
      currHP = maxHP;
    }
  }
  void setCurrentHPAttack(double additionalHP) { currHP -= additionalHP; }

  void setName(const string& newName);
  void setMaxHP(double newMaxHP);
  void setAttack(double newAttack);
  void setDefense(double newDefense);
  void setLevel(int level);
  void setRole(characterType Role);

  // Utility methods
  bool isAlive() const;
  virtual void takeDamage(double amount) = 0;

  virtual string NameMaker() = 0;
  characterType getcharType() const { return role; }
};

#endif /* CHARACTER_H */
