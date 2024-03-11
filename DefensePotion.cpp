#include "DefensePotion.h"
#include <iostream>

using namespace std;

void DefensePotion::increaseDefense(chara& target) {
  cout << "Defense Increased!";
}
DefensePotion::DefensePotion(string name,
                             double price,
                             bool vIP,
                             double potency)
    : Consumable(name, price, vIP, potency) {}