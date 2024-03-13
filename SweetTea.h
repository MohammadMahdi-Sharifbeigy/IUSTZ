#ifndef SWEETTEA_H
#define SWEETTEA_H

#include "Consumable.h"
using namespace std;

class chara;

class SweetTea : public Consumable
{
public:
    SweetTea(string name, double price, bool vIP, double potency);
    void increaseHP(chara &target);
};

#endif