#include "HealingPotion.h"
#include <iostream>

using namespace std;

void HealingPotion::increaseHP(chara& target) {
  cout << "HP Increased!";
}
HealingPotion::HealingPotion(string name,
                             double price,
                             bool vIP,
                             double potency)
    : Consumable(name, price, vIP, potency) {}