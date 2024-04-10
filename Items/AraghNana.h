#ifndef ARAGHNANA_H
#define ARAGHNANA_H

#include "../Characters/Character.h"
#include "Consumable.h"
using namespace std;

class AraghNana : public Consumable {
 public:
  AraghNana(string name, double price, bool vIP, double potency, int count);
  void increaseDefense(Character& target);
};

#endif