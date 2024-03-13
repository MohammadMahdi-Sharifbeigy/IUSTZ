    #ifndef NINJASTAR_H
    #define NINJASTAR_H

    #include <iostream>
    #include "Throwable.h"
    using namespace std;

    class NinjaStar : public Throwable {
    public:
    NinjaStar (string name, double price, bool vIP, int number, double synergydamage);
    };
    
    #endif