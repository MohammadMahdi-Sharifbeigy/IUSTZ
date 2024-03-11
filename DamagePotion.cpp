#include "DamagePotion.h"
#include <iostream>

using namespace std;

void DamagePotion::increaseDamage(chara& target) {
  cout << "Damage Increased!";
}
DamagePotion::DamagePotion(string name, double price, bool vIP, double potency)
    : Consumable(name, price, vIP, potency) {}