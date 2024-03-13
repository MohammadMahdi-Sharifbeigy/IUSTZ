#ifndef SWATTER_H
#define SWATTER_H

#include <iostream>
#include "Passive.h"
using namespace std;

class Swatter : public Passive {
 public:
  Swatter(string name,
       double price,
       bool vIP,
       string perk,
       string type,
       double synergyDamage);
     };

#endif  