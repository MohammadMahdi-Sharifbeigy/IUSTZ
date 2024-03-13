#ifndef LASERGUN_H
#define LASERGUN_H

#include <iostream>
#include "Passive.h"
using namespace std;

class LaserGun : public Passive {
 public:
  LaserGun(string name,
           double price,
           bool vIP,
           string perk,
           string type,
           double synergyDamage);
};

#endif  // LASERGUN_H
