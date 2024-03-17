#include <iostream>
#include "Swatter.h"
using namespace std;

Swatter::Swatter(string name,
                 double price,
                 bool vIP,
                 string perk,
                 string type,
                 double synergyDamage,
                 int count)
    : Passive(name, price, vIP, perk, type, synergyDamage, count){};
