#include "Bow.h"
#include <iostream>
using namespace std;

Bow::Bow(string name,
           double price,
           bool vIP,
           int number,
           double synergyDamage)
            : Throwable ( name, price, vIP, number, synergyDamage){};