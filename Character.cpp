#include "Character.h"
#include "CharacterType.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <random>

using namespace std;


Character::Character(const string &name,
                     double hp,
                     int lvl,
                     double attack,
                     double defense,
                     characterType role)
    : name(name),
      currHP(hp),
      maxHP(hp),
      level(lvl),
      role(role),
      attack(attack),
      defense(defense)
{
}

Character::~Character() = default;

string Character::getName() const
{
  return name;
}

double Character::getMaxHP() const
{
  return maxHP;
}

double Character::getCurrentHP() const
{
  return currHP;
}

double Character::getAttack() const
{
  return attack;
}

double Character::getDefense() const
{
  return defense;
}

int Character::getLevel() const
{
  return level;
}

characterType Character::getRole() const
{
  return role;
}

void Character::setName(const string &newName)
{
  name = newName;
}

void Character::setMaxHP(double newMaxHP)
{
  maxHP = newMaxHP;
}

void Character::setAttack(double newAttack)
{
  attack = newAttack;
}

void Character::setDefense(double newDefense)
{
  defense = newDefense;
}

void Character::setLevel(int newLevel)
{
  level = newLevel;
}

void Character::setRole(characterType newRole)
{
  role = newRole;
}

bool Character::isAlive() const
{
  return currHP > 0;
}
void Character::takeDamage() {};
