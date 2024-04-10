#include "Zombie.h"
#include <iostream>

using namespace std;

Zombie::Zombie(const string& name,
               double hp,
               int level,
               double attack,
               double defense,
               characterType role)
    : Character(name, hp, level, attack, defense, role){};

int Zombie::attack_func(Human* curenemy) {
  double damage = this->getAttack() - curenemy->getDefense();
  if (damage < 0) {
    damage = 0;
  }
  curenemy->setCurrentHPAttack(damage);
  cout << this->getName() << " attacked " << curenemy->getName() << " for "
       << damage << " damage." << endl;
  return damage;
};

void Zombie::takeDamage(double amount) {
  double damage = amount - this->getDefense();
  if (damage < 0) {
    damage = 0;
  }
  this->setCurrentHPAttack(damage);
  cout << this->getName() << " took " << damage << " damage." << endl;
  if (this->getCurrentHP() <= 0) {
    cout << this->getName() << " has died." << endl;
  }
}
