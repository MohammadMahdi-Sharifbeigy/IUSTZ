#ifndef HUMAN_H
#define HUMAN_H

#include "Character.h"
#include "Item.h"
#include "State.h"
#include <sstream>
#include <string.h>
#include "CheckNumber.h"

using namespace std;

class Human : public Character {
 protected:
string username;
  int age;
  int maxXP;
  int currXP;
  double stamina;
  double strength;
  double endurance;
  double accuracy;
  double pace;
  double mind;
  int coin;
  State state;
  Item* armor = nullptr;
  Item* weapon = nullptr;
  vector<Item*> inventory;

 public:
  Human() = default;
  Human(const string& name,
        int age,
        double hp,
        double attack,
        double defense,
        characterType role) {
    this->name = name;
    this->age = age;
    this->maxHP = hp;
    this->currHP = hp;
    this->attack = 10;
    this->defense = 5;
    this->role = role;
    this->level = 1;
    this->currXP = 90;
    this->maxXP = 100;
  };
  virtual void performAttack(Character& target) = 0;
  virtual void performDefense(Character& attacker) = 0;
  virtual void performAttack(Human& target) = 0;
  virtual void performDefense(Human& attacker) = 0;
  virtual string NameMaker() override;
  virtual void levelUp() override;
  virtual void takeDamage(double amount) override;
    string getUserName();
    void setUserName(string username);
  int getAge();
  void setName(int age);
  int getCurrXP();
  void setCurrXP(int currXP);
  int getMaxXP();
  void setMaxXP(int maxXP);
  int getNextLevelXP(int maxXP, int currXP);
  double getStamina();
  void setStamina(double stamina);
  double getStrength();
  void setStrength(double strength);
  double getEndurance();
  void setEndurance(double endurance);
  double getAccuracy();
  void setAccuracy(double accuracy);
  double getPace();
  void setPace(double pace);
  double getMind();
  void setMind(double mind);
  int getCoin();
  void setCoin(int coin);
  void setStateBasedOnHP();
    State getState();
    void setState(State state);
  vector<Item*> getInventory();
  // Item Functions
    void clearInventory();
  double chooseDefItems();
  double chooseAtkItem();
  Item* choosePotion();
  Item* itemsAt(int index);
  void showInventory();
  void addInventory(Item* item);
  void removeInventory(int index);
  void addInventory(Item* item, int count);
  void removeInventory(int index, int count);
  int inventorySize();
  bool existInInventory(Item* item);
  int countInInventory(Item* item);
  int indexInInventory(Item* item);
  double priceItemsAt(int index);
  int countItemsAt(int index);
  Item* getArmor();
  Item* getWeapon();
  void setArmor(Item* armor);
  void setWeapon(Item* weapon);
  Item* stringToItem(const string& line);
};

#endif /* Human_h */
