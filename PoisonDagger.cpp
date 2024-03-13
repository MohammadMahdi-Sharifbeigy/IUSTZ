#include "PoisonDagger.h"
#include <iostream>
using namespace std;

PoisonDagger::PoisonDagger(string name,
                           double price,
                           bool vIP,
                           string perk,
                           string type,
                           double synergyDamage)
    : Passive(name, price, vIP, perk, type, synergyDamage){};