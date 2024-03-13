#ifndef SAFFRON_H
#define SAFFRON_H

#include "Consumable.h"
using namespace std;

class chara;

class Saffron : public Consumable
{
public:
  Saffron(string name, double price, bool vIP, double potency);
  void increaseDamage(chara &target);
};

#endif