#include "SpiderNet.h"
#include <iostream>
using namespace std;

SpiderNet::SpiderNet(string name,
                     double price,
                     bool vIP,
                     double synergyDamage,
                     int count)
    : Throwable(name, price, vIP, synergyDamage, count){};