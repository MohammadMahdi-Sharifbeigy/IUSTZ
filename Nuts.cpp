#include "Nuts.h"
#include <iostream>

using namespace std;

void Nuts::increaseStamina(chara &target)
{
    cout << "Stamina Increased Dear Mom!";
}
Nuts::Nuts(string name,
           double price,
           bool vIP,
           double potency)
    : Consumable(name, price, vIP, potency) {}