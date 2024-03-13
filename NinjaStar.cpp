#include "NinjaStar.h"
#include <iostream>
using namespace std;

NinjaStar::NinjaStar(string name,
           double price,
           bool vIP,
           int number,
           double synergyDamage)
            : Throwable ( name, price, vIP, number, synergyDamage){};