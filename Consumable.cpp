#include "Consumable.h"

using namespace std;

Consumable::Consumable(string name,
                       double price,
                       bool vIP,
                       double potency,
                       int count)
    : Item(name, price, vIP, count) {
  this->potency = potency;
}

Consumable::~Consumable(){};

double Consumable::getPotency() {
  return potency;
}

void Consumable::setPotency(double newPotency) {
  potency = newPotency;
}
