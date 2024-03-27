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
  Item(const string& name, double price, bool VIP, int count);
  virtual ~Item();

  string getName() const;
  double getPrice() const;
  int getCount() const;
  bool isVIP() const;

  void setCount(int newCount);
};

#endif  // ITEM_H
