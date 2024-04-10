#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include "Passive.h"
using namespace std;

class Book : public Passive {
 public:
  Book(string name,
       double price,
       bool vIP,
       string perk,
       string type,
       double synergyDamage,
       int count);
};

#endif  // Book_H