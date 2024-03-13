#ifndef HEALINGPOTION_H
#define HEALINGPOTION_H

#include <string>
#include "Consumable.h"
using namespace std;

class chara;

class HealingPotion : public Consumable {
 public:
  HealingPotion(string name, double price, bool vIP, double potency);
  void increaseHP(chara& target);
};

#endif