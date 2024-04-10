#ifndef COLT_H
#define COLT_H

#include <iostream>
#include "Passive.h"
using namespace std;

class Colt : public Passive {
 public:
  Colt(string name,
       double price,
       bool vIP,
       string perk,
       string type,
       double synergyDamage,
       int count);
};

#endif  // COLT_H
