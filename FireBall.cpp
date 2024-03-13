#include "FireBall.h"
#include <iostream>
using namespace std;

FireBall::FireBall(string name,
           double price,
           bool vIP,
           int number,
           double synergyDamage)
            : Throwable ( name, price, vIP, number, synergyDamage){};