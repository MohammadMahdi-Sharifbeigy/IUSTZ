    #ifndef GRENADE_H
    #define GRENADE_H

    #include <iostream>
    #include "Throwable.h"
    using namespace std;

    class Grenade : public Throwable {
    public:
    Grenade (string name, double price, bool vIP, int number, double synergydamage);
    };
    
    #endif