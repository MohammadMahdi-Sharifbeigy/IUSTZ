#include "Throwable.h"

using namespace std;

Throwable::Throwable(string name,
                     double price,
                     bool vIP,
                     double synergydamage,
                     int count)
    : Item(name, price, vIP, count) {
  this->Synergydamage = synergydamage;
}
Throwable::~Throwable(){};

double Throwable::getSynengyDmg() {
  return Synergydamage;
}