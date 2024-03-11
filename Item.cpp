#include "Item.h"
using namespace std;

Item::Item(const string& name, double price) : name(name), price(price) {}

Item::~Item() {}

string Item::getName() const {
  return name;
}
double Item::getPrice() const {
  return price;
}

void Item::setName(const string& newName) {
  name = newName;
}
void Item::setPrice(double newPrice) {
  price = newPrice;
}
