    #ifndef BOW_H
    #define BOW_H

    #include <iostream>
    #include "Throwable.h"
    using namespace std;

    class Bow : public Throwable {
    public:
    Bow(string name, double price, bool vIP, int number, double synergydamage);
    };
    #endif