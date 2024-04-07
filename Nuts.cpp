#include "Nuts.h"
#include <iostream>

using namespace std;

Nuts::Nuts(string name, double price, bool vIP, double potency, int count)
    : Consumable(name, price, vIP, potency, count) {this->ID=37;}

void Nuts::increaseStamina(Human& target) {
    target.setStamina(target.getStamina() + potency);
    cout << target.getName() << "'s stamina has increased by " << potency
    << " points." << endl;}
//   count--;
//   if (count == 0) {
//     cout << "You have run out of " << name << "." << endl;
//   }
