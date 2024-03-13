#ifndef SPEAR_H
#define SPEAR_H

#include <iostream>
#include "Passive.h"
using namespace std;

class Character;

class Spear : public Passive {
 public:
  Spear(string name,
        double price,
        bool vIP,
        string perk,
        string type,
        double synergyDamage);
};

#endif  // SPEAR_H