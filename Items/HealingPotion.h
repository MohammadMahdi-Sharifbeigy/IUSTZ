#ifndef HEALINGPOTION_H
#define HEALINGPOTION_H

#include <string>
#include "Consumable.h"
#include "../Characters/Character.h"
#include "../Characters/Humans/Human.h"

using namespace std;

class HealingPotion : public Consumable {
 public:
  HealingPotion(string name, double price, bool vIP, double potency, int count);
  void increaseHP(Human& target);
};

#endif