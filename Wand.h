#ifndef WAND_H
#define WAND_H

#include <iostream>
#include "Passive.h"
using namespace std;

class Character;

class Wand : public Passive {
 public:
  Wand(string name,
         double price,
         bool vIP,
         string perk,
         string type,
         double synergyDamage);
};

#endif  // Wand_H