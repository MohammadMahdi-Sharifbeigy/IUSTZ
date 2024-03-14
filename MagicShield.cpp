#include "MagicShield.h"
#include <iostream>
#include "Passive.h"

using namespace std;

MagicShield::MagicShield(string name,
                         double price,
                         bool vIP,
                         string perk,
                         string type,
                         double synergyDamage)
    : Passive(name, price, vIP, perk, type, synergyDamage) {}