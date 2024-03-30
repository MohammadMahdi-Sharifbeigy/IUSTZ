#include "Grenade.h"
#include <iostream>
using namespace std;

Grenade::Grenade(string name,
                 double price,
                 bool vIP,
                 double synergyDamage,
                 int count)
    : Throwable(name, price, vIP, synergyDamage, count), ID(26){};
