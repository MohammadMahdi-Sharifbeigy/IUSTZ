#include "Colt.h"
#include <iostream>
using namespace std;

Colt::Colt(string name,
           double price,
           bool vIP,
           string perk,
           string type,
           double synergyDamage, int count)
    : Passive(name, price, vIP, perk, type, synergyDamage, count){this->ID=17;};
