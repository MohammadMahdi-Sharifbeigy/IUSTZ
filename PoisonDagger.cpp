#include "PoisonDagger.h"
#include <iostream>
using namespace std;

PoisonDagger::PoisonDagger(string name,
                           double price,
                           bool vIP,
                           string perk,
                           string type,
                           double synergyDamage,
                           int count)
    : Passive(name, price, vIP, perk, type, synergyDamage, count), IDE(11){};
