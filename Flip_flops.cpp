#include "Flip_flops.h"
#include <iostream>
using namespace std;

Flipflops::Flipflops(string name,
                     double price,
                     bool vIP,
                     double synergyDamage,
                     int count)
    : Throwable(name, price, vIP, synergyDamage, count), ID(27){};
