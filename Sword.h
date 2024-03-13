#ifndef SWORD_H
#define SWORD_H

#include <iostream>
#include "Passive.h"
using namespace std;

class Character;

class Sword : public Passive {
 public:
  Sword(string name,
        double price,
        bool vIP,
        string perk,
        string type,
        double synergyDamage);
};

#endif