#ifndef CLOAK_H
#define CLOAK_H

#include "Passive.h"
using namespace std;

class Cloak : public Passive {
 public:
  Cloak(string name,
        double price,
        bool vIP,
        string perk,
        string type,
        double synergyDamage);
};

#endif