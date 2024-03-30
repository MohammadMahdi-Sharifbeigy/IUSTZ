#include "FireBall.h"
#include <iostream>
using namespace std;

FireBall::FireBall(string name,
                   double price,
                   bool vIP,
                   double synergyDamage,
                   int count)
    : Throwable(name, price, vIP, synergyDamage, count){this->ID=24;};
