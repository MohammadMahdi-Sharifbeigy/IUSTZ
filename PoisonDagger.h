#ifndef POISONDAGGER_H
#define POISONDAGGER_H

#include <iostream>
#include "Passive.h"
using namespace std;

class Character;

class PoisonDagger : public Passive {
 public:
  PoisonDagger(string name,
         double price,
         bool vIP,
         string perk,
         string type,
         double synergyDamage);
};

#endif  // POISONDAGGER_H