#include "Bow.h"
#include <iostream>
using namespace std;

Bow::Bow(string name, double price, bool vIP, double synergyDamage, int count)
    : Throwable(name, price, vIP, synergyDamage, count){this->ID=22;};
