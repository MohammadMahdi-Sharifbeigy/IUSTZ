#include "Grenade.h"
#include <iostream>
using namespace std;

Grenade::Grenade(string name,
           double price,
           bool vIP,
           int number,
           double synergyDamage)
            : Throwable ( name, price, vIP, number, synergyDamage){};