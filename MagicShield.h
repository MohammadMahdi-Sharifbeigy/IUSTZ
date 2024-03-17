#ifndef MAGICSHIELD_H
#define MAGICSHIELD_H

#include "Passive.h"
using namespace std;

class MagicShield : public Passive {
 public:
  MagicShield(string name,
              double price,
              bool vIP,
              string perk,
              string type,
              double synergyDamage,
              int count);
};

#endif