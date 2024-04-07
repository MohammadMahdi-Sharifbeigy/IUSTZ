#include "SweetTea.h"
#include <iostream>

using namespace std;

SweetTea::SweetTea(string name,
                   double price,
                   bool vIP,
                   double potency,
                   int count)
    : Consumable(name, price, vIP, potency, count){this->ID=34;}

void SweetTea::increaseHP(Character& target) {
  target.setCurrentHP(target.getCurrentHP() + potency);
  cout << target.getName() << "'s HP has increased by " << potency << " points."
       << endl;
 // count--;
//  if (count == 0) {
//    cout << "You have run out of " << name << "." << endl;
//  }
}
