#ifndef DAMAGEPOTION_H
#define DAMAGEPOTION_H

#include "Consumable.h"
using namespace std;

class chara;

class DamagePotion : public Consumable {
 public:
  DamagePotion(string name, double price, bool vIP, double potency);
  void increaseDamage(chara& target);
};

#endif  // DAMAGEPOTION_H