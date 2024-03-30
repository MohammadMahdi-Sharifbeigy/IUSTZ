#include "AraghNana.h"
#include <iostream>

using namespace std;

AraghNana::AraghNana(string name,
                     double price,
                     bool vIP,
                     double potency,
                     int count)
    : Consumable(name, price, vIP, potency, count)  {this->ID=36;}

void AraghNana::increaseDefense(Character& target) {
  target.setDefense(target.getDefense() + getPotency());
}
