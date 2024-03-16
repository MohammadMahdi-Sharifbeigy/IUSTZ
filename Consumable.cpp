#include "Consumable.h"

using namespace std;

Consumable::Consumable(string name,
                       double price,
                       bool vIP,
                       double potency)
    : Item(name, price, vIP) {
  this->potency = potency;
}

Consumable::~Consumable(){};

double Consumable::getPotency() {
  return potency;
}

void Consumable::setPotency(double newPotency) {
  potency = newPotency;
}

