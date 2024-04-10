#ifndef NUTS_H
#define NUTS_H

#include "Consumable.h"
#include "../Characters/Character.h"

using namespace std;

class Nuts : public Consumable {
 public:
  Nuts(string name, double price, bool vIP, double potency, int count);
  void increaseStamina(Character& target);
};

#endif