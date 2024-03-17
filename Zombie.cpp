//
//  Zombie.cpp
//  
//
//  Created by Lilia Rouhi on 12/21/1402 AP.
//

#include "Zombie.hpp"
#include <Zombie.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <random>


using namespace std;
using namespace Zombie;


Zombie() = default;
virtual int attack_func(Human* curenemy) = 0;
virtual void takeDamage()=0;

