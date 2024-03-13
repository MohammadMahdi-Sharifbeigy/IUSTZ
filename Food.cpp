#include "Food.h"
#include <iostream>

using namespace std;

void Food::increaseStats(chara& target) {
  cout << "All Stats Increased!";
}
Food::Food(string name, double price, bool vIP, double potency)
    : Consumable(name, price, vIP, potency) {}