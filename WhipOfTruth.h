#ifndef WHIPOFTRUTH_H
#define WHIPOFTRUTH_H

#include <iostream>
#include "Passive.h"
using namespace std;

class WhipOfTruth : public Passive {
 public:
  WhipOfTruth(string name,
              double price,
              bool vIP,
              string perk,
              string type,
              double synergyDamage);
};

#endif  // WHIPOFTRUTH_H
