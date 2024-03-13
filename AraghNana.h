#ifndef ARAGHNANA_H
#define ARAGHNANA_H

#include "Consumable.h"
using namespace std;

class chara;

class AraghNana : public Consumable
{
public:
    AraghNana(string name, double price, bool vIP, double potency);
    void increaseDefense(chara &target);
};

#endif