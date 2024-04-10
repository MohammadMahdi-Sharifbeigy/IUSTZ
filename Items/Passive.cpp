#include "Passive.h"
#include <iostream>

using namespace std;

class Character;

Passive::Passive(string name,
                 double price,
                 bool vIP,
                 string perk,
                 string type,
                 double synergyDamage,
                 int count)
    : Item(name, price, vIP, count) {
  Perk = perk;
  SynergyDamage = synergyDamage;
  Type = type;
};

Passive::~Passive(){};

double Passive::getSynergyDamage() {
  return SynergyDamage;
};

string Passive::getPerk() {
  return Perk;
}
string Passive::getType() {
  return Type;
}