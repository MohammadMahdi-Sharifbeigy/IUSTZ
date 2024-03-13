#ifndef FOOD_H
#define FOOD_H

#include <string>
#include "Consumable.h"
using namespace std;

class chara;

class Food : public Consumable {
 public:
  Food(string name, double price, bool vIP, double potency);
  void increaseStats(chara& target);
};

#endif  // FOOD_H