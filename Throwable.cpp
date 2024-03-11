#include "Throwable.h"

using namespace std;

Throwable::Throwable(string name, double price, bool vIP, int number, double synergydamage) : Item(name, price, vIP)
{
    this->Number = number;
    this->Synergydamage = synergydamage;
}
Throwable::~Throwable(){};
double Throwable::getSynengyDmg()
{
    return Synergydamage;
}
double Throwable::getNumber()
{
    return Number;
}