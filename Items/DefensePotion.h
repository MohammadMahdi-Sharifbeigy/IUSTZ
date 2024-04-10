#ifndef DEFENSEPOTION_H
#define DEFENSEPOTION_H

#include "Consumable.h"
#include "../Characters/Character.h"

using namespace std;

class DefensePotion : public Consumable {
 public:
  DefensePotion(string name, double price, bool vIP, double potency, int count);
  void increaseDefense(Character& target);
};

#endif  // DEFENSEPOTION_H