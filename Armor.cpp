#include "Armor.h"
#include <iostream>
#include "Passive.h"

using namespace std;

Armor::Armor(string name,
             double price,
             bool vIP,
             string perk,
             string type,
             double synergyDamage)
    : Passive(name, price, vIP, perk, type, synergyDamage) {}