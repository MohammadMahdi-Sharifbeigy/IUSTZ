#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Character;  // Forward declaration

class Item {
 protected:
  string name;
  double price;
  bool VIP;

 public:
  Item(const string& name, double price, bool VIP = false);
  virtual ~Item();

  virtual void use(Character& target) = 0;

  // Getters and setters
  string getName() const;
  double getPrice() const;
  bool isVIP() const;

  void setName(const string& newName);
  void setPrice(double newPrice);
  void setVIP(bool newVIP);
};

#endif  // ITEM_H
