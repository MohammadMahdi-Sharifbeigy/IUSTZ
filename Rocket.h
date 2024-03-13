    #ifndef ROCKET_H
    #define ROCKET_H

    #include <iostream>
    #include "Throwable.h"
    using namespace std;

    class Rocket : public Throwable {
    public:
    Rocket (string name, double price, bool vIP, int number, double synergydamage);
    };
    
    #endif