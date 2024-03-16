#include "Throwable.h"

using namespace std;

Throwable::Throwable(string name,
                     double price,
                     bool vIP,
                     int number,
                     double synergydamage)
    : Item(name, price, vIP) {
  this->Number = number;
  this->Synergydamage = synergydamage;
}
Throwable::~Throwable(){};
double Throwable::getSynengyDmg() {
  return Synergydamage;
}
int Throwable::getNumber() {
  return Number;
}
void Throwable::setNumber(int newNumber) {
  Number = newNumber;
}