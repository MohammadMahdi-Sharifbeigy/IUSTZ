#include "Passive.h"
#include <iostream>

using namespace std;

class Character;

Passive::Passive(string name,
                 double price,
                 bool vIP,
                 string perk,
                 string type,
                 double synergyDamage)
    : Item(name, price, vIP) {
  Perk = perk;
  SynergyDamage = synergyDamage;
  Type = type;
};
double Passive::getSynergyDamage() {
  return SynergyDamage;
};

string Passive::getPerk() {
  return Perk;
}
string Passive::getType() {
  return Type;
}