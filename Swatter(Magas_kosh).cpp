#include "Swatter(Magas_kosh).h"
#include <iostream>
using namespace std;

Swatter::Swatter(string name,
           double price,
           bool vIP,
           string perk,
           string type,
           double synergyDamage)
           : Passive(name, price, vIP, perk, type, synergyDamage){};
            