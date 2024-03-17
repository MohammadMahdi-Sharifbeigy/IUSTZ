#ifndef Zombie_h
#define Zombie_h
#include "Character.h"
#include "Human.h"

class Zombie : public Character {
 public:
  Zombie(const string& name,
         double hp,
         int level,
         double attack,
         double defense,
         characterType role);
  int attack_func(Human* curenemy);
  void takeDamage(double amount);
};

#endif /* Zombie_h */
