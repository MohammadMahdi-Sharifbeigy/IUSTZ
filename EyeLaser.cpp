#include "EyeLaser.h"
#include <iostream>
using namespace std;

EyeLaser::EyeLaser(string name,
                   double price,
                   bool vIP,
                   string perk,
                   string type,
                   double synergyDamage, int count)
    : Passive(name, price, vIP, perk, type, synergyDamage, count){};
