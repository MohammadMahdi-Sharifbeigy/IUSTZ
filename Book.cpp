#include "Book.h"
#include <iostream>
using namespace std;

Book::Book(string name,
           double price,
           bool vIP,
           string perk,
           string type,
           double synergyDamage)
    : Passive(name, price, vIP, perk, type, synergyDamage){};