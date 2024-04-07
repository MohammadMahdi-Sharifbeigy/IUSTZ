#ifndef STAMINAPOTION_H
#define STAMINAPOTION_H

//#include "Character.h"
#include "Consumable.h"
#include "Human.h"
using namespace std;

class StaminaPotion : public Consumable {
 public:
  StaminaPotion(string name, double price, bool vIP, double potency, int count);
  void increaseStamina(Human& target);
};

#endif  // STAMINAPOTION_H
