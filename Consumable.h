#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include <string>
#include "Item.h"
using namespace std;

class Consumable : public Item
{

protected:
    double potency;
    int number;

public:
    Consumable(string name, double price, bool vIP, double potency, int number);
    virtual ~Consumable();
    double getPotency();
    void setPotency(double newPotency);
    int getNumber();
    void setNumber(int newNumber);
};

#endif