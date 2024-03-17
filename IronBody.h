#ifndef IRONBODY_H
#define IRONBODY_H

#include "Passive.h"
using namespace std;

class IronBody : public Passive {
 public:
  IronBody(string name,
           double price,
           bool vIP,
           string perk,
           string type,
           double synergyDamage,
           int count);
};

#endif