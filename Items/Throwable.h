#ifndef THROWABLE_H
#define THROWABLE_H

#include <string>
#include "Item.h"
using namespace std;

class Throwable : public Item {
 protected:
  double Synergydamage;

 public:
  Throwable(string name,
            double price,
            bool vIP,
            double synergydamage,
            int count);
  virtual ~Throwable();
  double getSynergyDmg();
};

#endif
