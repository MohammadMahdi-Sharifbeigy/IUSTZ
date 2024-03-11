#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Character;  // Forward declaration

class Item {
 protected:
  string name;
  double price;

 public:
  Item(const string& name, double price);
  virtual ~Item();

  virtual void use(Character& target) = 0;

  // Getters and setters
  string getName() const;
  double getPrice() const;

  void setName(const string& newName);
  void setPrice(double newPrice);
};

#endif  // ITEM_H
