#include "SweetTea.h"
#include <iostream>

using namespace std;

void SweetTea::increaseHP(chara &target)
{
    cout << "HP Increased Dear Mom!";
}
SweetTea::SweetTea(string name,
                   double price,
                   bool vIP,
                   double potency)
    : Consumable(name, price, vIP, potency) {}