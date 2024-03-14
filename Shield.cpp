#include "Shield.h"
#include <iostream>
#include "Passive.h"

using namespace std;

Shield::Shield(string name,
               double price,
               bool vIP,
               string perk,
               string type,
               double synergyDamage)
    : Passive(name, price, vIP, perk, type, synergyDamage) {}