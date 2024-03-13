#include "Saffron.h"
#include <iostream>

using namespace std;

void Saffron::increaseDamage(chara& target) {
  cout << "Damage Increased Dear Mom!";
}
Saffron::Saffron(string name,
                double price,
                bool vIP,
                double potency)
               : Consumable(name, price, vIP, potency) {}