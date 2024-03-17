#include "Food.h"
#include <iostream>

using namespace std;

Food::Food(string name, double price, bool vIP, double potency, int count)
    : Consumable(name, price, vIP, potency, count) {}

void Food::increaseStats(Character& target) {
  target.setCurrentHP(target.getCurrentHP() + potency);
  cout << target.getName() << "'s health has increased by " << potency
       << " points." << endl;
  count--;
  if (count == 0) {
    cout << "You have run out of " << name << "." << endl;
  }
}