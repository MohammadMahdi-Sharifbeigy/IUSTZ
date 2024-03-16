#include "Throwable.h"

using namespace std;

Throwable::Throwable(string name,
                     double price,
                     bool vIP,
                     double synergydamage)
    : Item(name, price, vIP) {
  this->Synergydamage = synergydamage;
}
Throwable::~Throwable(){};
double Throwable::getSynengyDmg() {
  return Synergydamage;
}