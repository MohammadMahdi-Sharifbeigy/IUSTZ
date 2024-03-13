#include "Flipflops.h"
#include <iostream>
using namespace std;

Flipflops::Flipflops(string name,
           double price,
           bool vIP,
           int number,
           double synergyDamage)
            : Throwable ( name, price, vIP, number, synergyDamage){};
