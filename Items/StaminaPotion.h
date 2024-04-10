#ifndef STAMINAPOTION_H
#define STAMINAPOTION_H

#include "Consumable.h"
#include "../Characters/Character.h"

using namespace std;

class StaminaPotion : public Consumable {
 public:
  StaminaPotion(string name, double price, bool vIP, double potency, int count);
  void increaseStamina(Character& target);
};

#endif  // STAMINAPOTION_H