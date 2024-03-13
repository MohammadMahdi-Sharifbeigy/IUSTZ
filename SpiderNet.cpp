#include "SpiderNet.h"
#include <iostream>
using namespace std;

SpiderNet::SpiderNet(string name,
           double price,
           bool vIP,
           int number,
           double synergyDamage)
            : Throwable ( name, price, vIP, number, synergyDamage){};