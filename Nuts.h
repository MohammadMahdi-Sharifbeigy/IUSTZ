#ifndef NUTS_H
#define NUTS_H

#include "Consumable.h"
using namespace std;

class chara;

class Nuts : public Consumable
{
public:
    Nuts(string name, double price, bool vIP, double potency);
    void increaseStamina(chara &target);
};

#endif