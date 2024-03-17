#include "StaminaPotion.h"
#include <iostream>

using namespace std;

StaminaPotion::StaminaPotion(string name,
                             double price,
                             bool vIP,
                             double potency,
                             int count)
    : Consumable(name, price, vIP, potency, count) {}

void StaminaPotion::increaseStamina(Character& target) {
  cout << "Stamina Increased!";
}