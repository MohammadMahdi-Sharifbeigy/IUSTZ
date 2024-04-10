#ifndef EYELASER_H
#define EYELASER_H

#include <iostream>
#include "Passive.h"
using namespace std;

class EyeLaser : public Passive {
 public:
  EyeLaser(string name,
           double price,
           bool vIP,
           string perk,
           string type,
           double synergyDamage,
           int count);
};

#endif  // EYELASER_H
