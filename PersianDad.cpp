#include "PersianDad.h"
#include <iostream>
#include "Passive.h"

using namespace std;

PersianDad::PersianDad(string name,
                       double price,
                       bool vIP,
                       string perk,
                       string type,
                       double synergyDamage, int count)
    : Passive(name, price, vIP, perk, type, synergyDamage, count)  {this->ID=7;}
