#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Character;

class Item {
 protected:
  string name;
  double price;
  bool VIP;

 public:
  Item(const string& name, double price, bool VIP = false);
  virtual ~Item();

  virtual void use(Character& target) = 0;

  string getName() const;
  double getPrice() const;
  bool isVIP() const;
};

#endif  // ITEM_H
