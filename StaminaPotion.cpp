#include "StaminaPotion.h"
#include <iostream>

using namespace std;

void StaminaPotion::increaseStamina(chara& target) {
  cout << "Stamina Increased!";
}
StaminaPotion::StaminaPotion(string name,
                             double price,
                             bool vIP,
                             double potency)
    : Consumable(name, price, vIP, potency) {}