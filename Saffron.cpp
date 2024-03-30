#include "Saffron.h"
#include <iostream>

using namespace std;

Saffron::Saffron(string name, double price, bool vIP, double potency, int count)
    : Consumable(name, price, vIP, potency, count) {this->ID=36;}

void Saffron::increaseDamage(Character& target) {
  target.setAttack(target.getAttack() + potency);
  cout << target.getName() << "'s damage has increased by " << potency
       << " points." << endl;
  count--;
  if (count == 0) {
    cout << "You have run out of " << name << "." << endl;
  }
}
