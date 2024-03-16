#include "Consumable.h"

using namespace std;

Consumable::Consumable(string name,
                       double price,
                       bool vIP,
                       double potency,
                       int number)
    : Item(name, price, vIP) {
  this->potency = potency;
  this->number = number;
}

Consumable::~Consumable(){};

double Consumable::getPotency() {
  return potency;
}

void Consumable::setPotency(double newPotency) {
  potency = newPotency;
}
int Consumable::getNumber() {
  return number;
}
void Consumable::setNumber(int newNumber) {
  number = newNumber;
}
