#include "DamagePotion.h"
#include <iostream>

using namespace std;

DamagePotion::DamagePotion(string name,
                           double price,
                           bool vIP,
                           double potency,
                           int count)
    : Consumable(name, price, vIP, potency, count), ID(30) {}

void DamagePotion::increaseDamage(Character& target) {
  target.setAttack(target.getAttack() + potency);
  cout << "Damage increased by " << potency << "!" << endl;
  count--;
  if (count == 0) {
    cout << "You have no more " << name << "s left!" << endl;
  }
}
