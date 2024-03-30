#include "NinjaStar.h"
#include <iostream>
using namespace std;

NinjaStar::NinjaStar(string name,
                     double price,
                     bool vIP,
                     double synergyDamage, int count)
    : Throwable(name, price, vIP, synergyDamage, count), ID(23){};
