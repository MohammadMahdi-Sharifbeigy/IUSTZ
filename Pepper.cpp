#include "Pepper.h"
#include <iostream>
using namespace std;

Pepper::Pepper(string name,
               double price,
               bool vIP,
               string perk,
               string type,
               double synergyDamage, int count)
    : Passive(name, price, vIP, perk, type, synergyDamage, count), ID(20){};
