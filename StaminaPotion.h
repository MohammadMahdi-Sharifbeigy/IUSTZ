#ifndef STAMINAPOTION_H
#define STAMINAPOTION_H

#include "Consumable.h"
using namespace std;

class chara;

class StaminaPotion : public Consumable {
 public:
  StaminaPotion(string name, double price, bool vIP, double potency);
  void increaseStamina(chara& target);
};

#endif  // STAMINAPOTION_H