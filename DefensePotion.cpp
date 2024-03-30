#include "DefensePotion.h"
#include <iostream>

using namespace std;

DefensePotion::DefensePotion(string name,
                             double price,
                             bool vIP,
                             double potency,
                             int count)
    : Consumable(name, price, vIP, potency, count) {this->ID=31;}

void DefensePotion::increaseDefense(Character& target) {
  target.setDefense(target.getDefense() + potency);
  cout << target.getName() << "'s defense has increased by " << potency
       << " points." << endl;
  count--;
  if (count == 0) {
    cout << "You have run out of " << name << "." << endl;
  }
}
