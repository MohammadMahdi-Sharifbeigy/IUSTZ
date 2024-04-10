#ifndef WHIPOFTRUTH_H
#define WHIPOFTRUTH_H

#include "Passive.h"
using namespace std;

class WhipOfTruth : public Passive {
 public:
  WhipOfTruth(string name,
              double price,
              bool vIP,
              string perk,
              string type,
              double synergyDamage,
              int count);
};

#endif  // WHIPOFTRUTH_H
