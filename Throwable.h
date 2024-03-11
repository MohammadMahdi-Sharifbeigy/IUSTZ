#ifndef THROWABLE_H
#define THROWABLE_H

#include <string>
#include "Item.h"
using namespace std;

class Throwable : public Item
{
protected:
    int Number;
    double Synergydamage;

public:
    Throwable(string name, double price, bool vIP, int number, double synergydamage);
    virtual ~Throwable();
    double getSynengyDmg();
    double getNumber();
};

#endif
