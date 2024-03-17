#include "HealingPotion.h"
#include <iostream>

using namespace std;

HealingPotion::HealingPotion(string name,
                             double price,
                             bool vIP,
                             double potency,
                             int count)
    : Consumable(name, price, vIP, potency, count) {}

void HealingPotion::increaseHP(Character& target) {
  target.setCurrentHP(target.getCurrentHP() + potency);
  cout << target.getName() << "'s HP has increased by " << potency << " points."
       << endl;
  count--;
  if (count == 0) {
    cout << "You have run out of " << name << "." << endl;
  }
}