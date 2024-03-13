    #ifndef FIREBALL_H
    #define FIREBALL_H

    #include <iostream>
    #include "Throwable.h"
    using namespace std;

    class FireBall : public Throwable {
    public:
    FireBall (string name, double price, bool vIP, int number, double synergydamage);
    };
    
    #endif