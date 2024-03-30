#include "Rocket.h"
#include <iostream>
using namespace std;

Rocket::Rocket(string name,
               double price,
               bool vIP,
               int number,
               double synergyDamage,
               int count)
    : Throwable(name, price, vIP, synergyDamage, count){this->ID=25;};
