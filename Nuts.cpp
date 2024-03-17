#include "Nuts.h"
#include <iostream>

using namespace std;

Nuts::Nuts(string name, double price, bool vIP, double potency, int count)
    : Consumable(name, price, vIP, potency, count) {}

// void Nuts::increaseStamina(Character& target) {
//   target.setCurrentStamina(target.getCurrentStamina() + potency);
//   cout << target.getName() << "'s stamina has increased by " << potency
//        << " points." << endl;
//   count--;
//   if (count == 0) {
//     cout << "You have run out of " << name << "." << endl;
//   }