#ifndef WAND_H
#define WAND_H

#include <iostream>
#include "Passive.h"
using namespace std;

class Wand : public Passive {
 public:
  Wand(string name,
       double price,
       bool vIP,
       string perk,
       string type,
       double synergyDamage,
       int count);
};

#endif  // Wand_H