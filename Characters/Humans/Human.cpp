#include <iostream>
#include <string>
#include <vector>
#include "Human.h"
#include "../../Items/Item.h"

using namespace std;

void Human::performAttack(Character& target) {}

void Human::performDefense(Character& attacker) {}

string Human::NameMaker() {
  return "";
}
void Human::takeDamage(double amount) {
  currHP -= amount;
  if (currHP < 0) {
    currHP = 0;
  }
  if (currHP > maxHP) {
    currHP = maxHP;
  }
};

void Human::levelUp() {
  level++;
  maxHP += 20;
  currHP = maxHP;
  stamina += 10;
  strength += 10;
  endurance += 10;
  accuracy += 10;
  pace += 10;
  mind += 10;
}

int Human::getAge() {
  return age;
}

void Human::setName(int age) {
  this->age = age;
}

int Human::getCurrXP() {
  return currXP;
}

void Human::setCurrXP(int currXP) {
  this->currXP = currXP;
}

int Human::getMaxXP() {
  return maxXP;
}

void Human::setMaxXP(int maxXP) {
  this->maxXP = maxXP;
}

int Human::getNextLevelXP(int maxXP, int CurrXP){
  return maxXP-CurrXP;
}

double Human::getStamina() {
  return stamina;
}

void Human::setStamina(double stamina) {
  this->stamina = stamina;
}

double Human::getStrength() {
  return strength;
}

void Human::setStrength(double strength) {
  this->strength = strength;
}

double Human::getEndurance() {
  return endurance;
}

void Human::setEndurance(double endurance) {
  this->endurance = endurance;
}

double Human::getAccuracy() {
  return accuracy;
}

void Human::setAccuracy(double accuracy) {
  this->accuracy = accuracy;
}

double Human::getPace() {
  return pace;
}

void Human::setPace(double pace) {
  this->pace = pace;
}

double Human::getMind() {
  return mind;
}

void Human::setMind(double mind) {
  this->mind = mind;
}

int Human::getCoin() {
  return coin;
}

void Human::setCoin(int coin) {
  this->coin = coin;
}

State Human::getState(){
    setStateBasedOnHP();
    return state;
}

void Human::setState(State state){
    this->state = state;
}

void Human::setStateBasedOnHP(){
   if(this->getCurrentHP() < (this->getMaxHP() * 20)/100){
        setState(State::NEARDEATH);
    }else if(this->getCurrentHP() < (this->getMaxHP() * 50)/100){
        setState(State::DEFENSE);
    }else{
        setState(State::ATTACK);
    }
        
        }

vector<Item*> Human::getInventory() {
  return inventory;
}

int Human::inventorySize() {
  return inventory.size();
}

Item* Human::itemsAt(int index) {
  if (this->inventorySize()) {
    return inventory.at(index - 1);
  }
  return nullptr;
}

void Human::showInventory() {
  if (this->inventorySize() > 0) {
    for (int i = 0; i < inventory.size(); i++) {
      cout << i + 1 << ". " << inventory[i]->getName()
           << " - count:" << inventory[i]->getCount() << endl;
    }
  } else {
    cout << "Your inventory is empty!" << endl;
  }
}

void Human::addInventory(Item* item) {
  int check = 0;
  if (this->inventorySize() > 0) {
    for (int i = 0; i < this->inventorySize(); i++) {
      if (item->getName() == inventory[i]->getName()) {
        inventory[i]->setCount(inventory[i]->getCount() + 1);
        check++;
        break;
      }
      if (check == 0) {
        inventory.push_back(item);
        //  inventory[inventory.size()-1]->setCount(1);
      }
    }
  } else {
    inventory.push_back(item);
    // inventory[inventory.size()-1]->setCount(1);
  }
}

void Human::removeInventory(int index) {
  if (index - 1 < this->inventorySize()) {
    if (inventory[index - 1]->getCount() == 1) {
      inventory.erase(inventory.begin() + index);
    } else {
      inventory[index - 1]->setCount(inventory[index - 1]->getCount() - 1);
    }
  }
}

void Human::addInventory(Item* item, int count) {
  int check = 0;
  if (this->inventorySize() > 0) {
    for (int i = 0; i < this->inventorySize(); i++) {
      if (item->getName() == inventory[i]->getName()) {
        inventory[i]->setCount(inventory[i]->getCount() + count);
        check++;
        break;
      }
      if (check == 0) {
        inventory.push_back(item);
        inventory[inventory.size() - 1]->setCount(count);
      }
    }
  } else {
    inventory.push_back(item);
    inventory[inventory.size() - 1]->setCount(count);
  }
}

void Human::removeInventory(int index, int count) {
  if (index - 1 < this->inventorySize()) {
    if (inventory[index - 1]->getCount() == count) {
      inventory.erase(inventory.begin() + index);
    } else if (inventory[index - 1]->getCount() > count) {
      inventory[index - 1]->setCount(inventory[index - 1]->getCount() - count);
    } else {
      cout << "You hav only " << inventory[index - 1]->getCount() << " "
           << inventory[index - 1]->getName() << "s you can't remove " << count
           << endl;
    }
  }
}

bool Human::existInInventory(Item* item) {
  for (int i = 0; i < this->inventory.size(); i++) {
    if (this->inventory[i]->getName() == item->getName()) {
      return true;
    }
  }
  return false;
}

int Human::countInInventory(Item* item) {
  for (int i = 0; i < this->inventory.size(); i++) {
    if (this->inventory[i]->getName() == item->getName()) {
      return inventory[i]->getCount();
    }
  }
  return 0;
}

int Human::indexInInventory(Item* item) {
  for (int i = 0; i < this->inventory.size(); i++) {
    if (this->inventory[i]->getName() == item->getName()) {
      return i;
    }
  }
  return -1;
}

double Human::priceItemsAt(int index) {
  return inventory[index - 1]->getPrice();
}

int Human::countItemsAt(int index) {
  return inventory[index - 1]->getCount();
}

Item* Human::getArmor() {
  return armor;
}

Item* Human::getWeapon() {
  return weapon;
}

// Item *Human::stringToItem(const string &line)
// {
//     Item *item = new ConcreteItem();
//     return item;
// }
// we need to add ConcreteItem() because of the item is abstracted class with
// pure functions;

void Human::setArmor(Item* aromor) {
  this->armor = aromor;
}

void Human::setWeapon(Item* weapon) {
  this->weapon = weapon;
}
