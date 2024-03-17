#ifndef SNIPE_H
#define SNIPE_H

#include <iostream>
#include "Passive.h"
using namespace std;

class Snipe : public Passive {
 public:
  Snipe(string name,
        double price,
        bool vIP,
        string perk,
        string type,
        double synergyDamage,
        int count);
};

#endif  // SNIPE_H
