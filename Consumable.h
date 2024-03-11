#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include <string>
#include "Item.h"
using namespace std;

class Consumeable : public Item
{

protected:
    double potency;

public:
    Consumeable(string name, double price, bool vIP, double potency);
    virtual ~Consumeable();
    double getPotency();
    void setPotency(double newPotency);
};

#endif