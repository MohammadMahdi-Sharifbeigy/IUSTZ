#ifndef SWORD_H
#define SWORD_H

#include "Passive.h"
using namespace std;

class Sword : public Passive {
 public:
  Sword(string name,
        double price,
        bool vIP,
        string perk,
        string type,
        double synergyDamage,
        int count);
};

#endif