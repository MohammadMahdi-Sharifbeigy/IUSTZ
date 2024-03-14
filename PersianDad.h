#ifndef PERSIANDAD_H
#define PERSIANDAD_H

#include "Passive.h"
using namespace std;

class PersianDad : public Passive {
 public:
  PersianDad(string name,
             double price,
             bool vIP,
             string perk,
             string type,
             double synergyDamage);
};

#endif