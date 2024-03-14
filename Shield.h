#ifndef SHIELD_H
#define SHIELD_H

#include "Passive.h"
using namespace std;

class chara;

class Shield : public Passive {
 public:
  Shield(string name,
         double price,
         bool vIP,
         string perk,
         string type,
         double synergyDamage);
};

#endif