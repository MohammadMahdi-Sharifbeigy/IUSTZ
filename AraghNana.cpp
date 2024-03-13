#include "AraghNana.h"
#include <iostream>

using namespace std;

void AraghNana::increaseDefense(chara &target)
{
    cout << "Defense Increased Dear Mom!";
}
AraghNana::AraghNana(string name,
                     double price,
                     bool vIP,
                     double potency)
    : Consumable(name, price, vIP, potency) {}