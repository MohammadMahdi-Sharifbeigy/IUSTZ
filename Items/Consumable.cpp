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

Consumable* Consumable::createConsumable(string name,
                                         double price,
                                         bool vIP,
                                         int count,
                                         Character* character) {
  double potency = character->getMaxHP() * 0.1;
  Consumable* consumable = new Consumable(name, price, vIP, potency, count);
  return consumable;
}