#ifndef DEFENSEPOTION_H
#define DEFENSEPOTION_H

#include "Consumable.h"
using namespace std;

class chara;

class DefensePotion : public Consumable {
 public:
  DefensePotion(string name, double price, bool vIP, double potency);
  void increaseDefense(chara& target);
};

#endif  // DEFENSEPOTION_H