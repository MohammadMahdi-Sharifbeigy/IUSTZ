#ifndef SWEETTEA_H
#define SWEETTEA_H

#include "Consumable.h"
#include "../Characters/Character.h"

using namespace std;

class SweetTea : public Consumable {
 public:
  SweetTea(string name, double price, bool vIP, double potency, int count);
  void increaseHP(Character& target);
};

#endif