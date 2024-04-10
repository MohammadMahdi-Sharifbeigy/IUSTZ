#ifndef SPIDERNET_H
#define SPIDERNET_H

#include <iostream>
#include "Throwable.h"
using namespace std;

class SpiderNet : public Throwable {
 public:
  SpiderNet(string name,
            double price,
            bool vIP,
            double synergydamage,
            int count);
};

#endif