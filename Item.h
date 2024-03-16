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
  int count;

 public:
  Item(const string& name, double price, bool VIP = false, int count);
  virtual ~Item();

  virtual void use(Character& target) = 0;

  string getName() const;
  double getPrice() const;
  bool isVIP() const;
  int getCount() const;
  void setCount(int newCount);
};

#endif  // ITEM_H
