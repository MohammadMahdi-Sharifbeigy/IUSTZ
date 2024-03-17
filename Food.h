#ifndef FOOD_H
#define FOOD_H

#include <string>
#include "Character.h"
#include "Consumable.h"
using namespace std;

class Food : public Consumable {
 public:
  Food(string name, double price, bool vIP, double potency, int count);
  void increaseStats(Character& target);
};

#endif  // FOOD_H