#ifndef HEALINGPOTION_H
#define HEALINGPOTION_H

#include <string>
#include "Character.h"
#include "Consumable.h"
#include "Human.h"
using namespace std;

class HealingPotion : public Consumable {
 public:
  HealingPotion(string name, double price, bool vIP, double potency, int count);
  void increaseHP(Human& target);
};

#endif