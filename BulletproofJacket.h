#ifndef BULLETPROOFJACKET_H
#define BULLETPROOFJACKET_H

#include "Passive.h"
using namespace std;

class BulletproofJacket : public Passive {
 public:
  BulletproofJacket(string name,
                    double price,
                    bool vIP,
                    string perk,
                    string type,
                    double synergyDamage,
                    int count);
};

#endif