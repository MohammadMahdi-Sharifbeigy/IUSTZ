#include "Rocket.h"
#include <iostream>
using namespace std;

Rocket::Rocket(string name,
           double price,
           bool vIP,
           int number,
           double synergyDamage)
            : Throwable ( name, price, vIP, number, synergyDamage){};