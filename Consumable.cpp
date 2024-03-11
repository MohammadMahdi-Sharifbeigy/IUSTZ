#include "Consumable.h"

using namespace std;

Consumeable::Consumeable(string name, double price, bool vIP, double potency) : Item(name, price, vIP)
{
    this->potency = potency;
}

Consumeable::~Consumeable(){};

double Consumeable::getPotency()
{
    return potency;
}

void Consumeable::setPotency(double newPotency)
{
    potency = newPotency;
}
