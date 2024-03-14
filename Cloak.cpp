#include "Cloak.h"
#include <iostream>
#include "Passive.h"

using namespace std;

Cloak::Cloak(string name,
             double price,
             bool vIP,
             string perk,
             string type,
             double synergyDamage)
    : Passive(name, price, vIP, perk, type, synergyDamage) {}
