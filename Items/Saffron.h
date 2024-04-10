#ifndef SAFFRON_H
#define SAFFRON_H

#include "Consumable.h"
#include "../Characters/Character.h"

using namespace std;

class Saffron : public Consumable {
 public:
  Saffron(string name, double price, bool vIP, double potency, int count);
  void increaseDamage(Character& target);
};

#endif