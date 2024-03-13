#include "Item.h"
using namespace std;

Item::Item(const string& name, double price, bool VIP)
    : name(name), price(price), VIP(VIP) {}

Item::~Item() {}

string Item::getName() const {
  return name;
}
double Item::getPrice() const {
  return price;
}

bool Item::isVIP() const {
  return VIP;
}

void Item::setName(const string& newName) {
  name = newName;
}
void Item::setPrice(double newPrice) {
  price = newPrice;
}

void Item::setVIP(bool newVIP) {
  VIP = newVIP;
}