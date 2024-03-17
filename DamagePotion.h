#ifndef DAMAGEPOTION_H
#define DAMAGEPOTION_H

#include "Character.h"
#include "Consumable.h"
using namespace std;

class DamagePotion : public Consumable {
 public:
  DamagePotion(string name, double price, bool vIP, double potency, int count);
  void increaseDamage(Character& target);
};

#endif  // DAMAGEPOTION_H