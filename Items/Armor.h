#ifndef ARMOR_H
#define ARMOR_H

#include "Passive.h"
using namespace std;

class Armor : public Passive {
 public:
  Armor(string name,
        double price,
        bool vIP,
        string perk,
        string type,
        double synergyDamage,
        int count);
};

#endif