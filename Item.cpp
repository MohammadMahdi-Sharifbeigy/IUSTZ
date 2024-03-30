#include "Item.h"

using namespace std;

Item::Item(const string& name, double price, bool VIP, int count)
    : name(name), price(price), VIP(VIP), count(count) {}

Item::~Item() {}

int Item::getID() const {
   return ID;
       }

string Item::getName() const {
  return name;
}
double Item::getPrice() const {
  return price;
}

bool Item::isVIP() const {
  return VIP;
}

int Item::getCount() const {
  return count;
}

void Item::setCount(int newCount) {
  count = newCount;
}
