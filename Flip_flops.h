    #ifndef FLIPFLOPS_H
    #define FLIPFLOPS_H

    #include <iostream>
    #include "Throwable.h"
    using namespace std;

    class Flipflops : public Throwable {
    public:
    Flipflops (string name, double price, bool vIP, int number, double synergydamage);
    };
    
    #endif