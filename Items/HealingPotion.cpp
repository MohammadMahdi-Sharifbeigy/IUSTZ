#include "HealingPotion.h"
#include <iostream>

using namespace std;

HealingPotion::HealingPotion(string name,
                             double price,
                             bool vIP,
                             double potency,
                             int count)
    : Consumable(name, price, vIP, potency, count){this->ID=29;};

void HealingPotion::increaseHP(Human& target) {
  target.setCurrentHP(target.getCurrentHP() + potency);
  cout << target.getName() << "'s HP has increased by " << potency << " points."
       << endl;
  cout << target.getName() << "'s current HP: " << target.getCurrentHP()
       << endl;
  count--;
  if (count == 0) {
    cout << "You have run out of " << name << "." << endl;
  }
}
