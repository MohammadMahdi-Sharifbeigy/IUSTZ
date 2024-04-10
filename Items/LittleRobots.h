#ifndef LITTLEROBOTS_H
#define LITTLEROBOTS_H

#include <iostream>
#include "Passive.h"
using namespace std;

class LittleRobots : public Passive {
 public:
  LittleRobots(string name,
               double price,
               bool vIP,
               string perk,
               string type,
               double synergyDamage,
               int count);
};

#endif  // LITTLEROBOTS_H
