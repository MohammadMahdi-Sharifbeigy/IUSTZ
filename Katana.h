#ifndef KATANA_H
#define KATANA_H

#include <iostream>
#include "Passive.h"
using namespace std;

class Character;

class Katana : public Passive {
 public:
  Katana(string name,
        double price,
        bool vIP,
        string perk,
        string type,
        double synergyDamage);
};

#endif  // KATANA_H