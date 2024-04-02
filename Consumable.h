#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include <string>
#include "Item.h"
#include "Character.h"
using namespace std;

class Consumable : public Item {
 protected:
  double potency;

 public:
  Consumable(string name, double price, bool vIP, double potency, int count);
  virtual ~Consumable();
  double getPotency();
  void setPotency(double newPotency);
  Consumable* createConsumable(string name, double price, bool vIP, int count, Character* character);
};

#endif