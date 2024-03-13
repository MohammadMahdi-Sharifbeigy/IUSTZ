#ifndef PASSIVE_H
#define PASSIVE_H

#include <string>
#include "Item.h"
using namespace std;

class Passive : public Item {
 protected:
  string Perk;
  double SynergyDamage;
  string Type;

 public:
  Passive(string name,
          double price,
          bool vIP,
          string perk,
          string type,
          double synergyDamage);
  virtual ~Passive();
  double getSynergyDamage();
  string getPerk();
  string getType();
};

#endif