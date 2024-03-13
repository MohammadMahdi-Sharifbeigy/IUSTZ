#ifndef PEPPER_H
#define PEPPER_H

#include <iostream>
#include "Passive.h"
using namespace std;

class Pepper : public Passive {
 public:
  Pepper(string name,
       double price,
       bool vIP,
       string perk,
       string type,
       double synergyDamage);
     };

#endif  