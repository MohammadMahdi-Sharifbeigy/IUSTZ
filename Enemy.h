#ifndef __ENEMY_H__
#define __ENEMY_H__
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <random>
#include <string>
#include "Character.h"
#include "CharacterType.h"
#include "Human.h"
#include "State.h"

using namespace std;

static int getRandomNumber(int a, int b) {
  random_device rd;
  mt19937 eng(rd());
  uniform_int_distribution<> distr(a, b);

  return distr(eng);
}

class Enemy : public Character {
 public:
  Enemy() {}
  Enemy(int characterLevel) {
    maxHP = 100;
    attack = 5;
    defense = 5;
    level = characterLevel;
    giveExp = level * 10 * attack / defense;
  }

 protected:
  int maxHP;
  int currHP;
  double attack;
  double defense;
  int level;
  int giveExp;
  int giveCoin;
  characterType role;

 public:
  virtual void takeDamage(double amount) override {
    currHP -= amount;
    if (currHP < 0) {
      currHP = 0;
    }
  };

  int getMaxHP() { return maxHP; }
    
  int getCurrentHP() { return currHP; }
    
  void setMaxHP (int maxHP) {this->maxHP = maxHP ;}
    
  void setCurrentHP (int currHP) {this->currHP = currHP ;}
    
  double get_enemy_atk() { return attack; }

  double get_enemy_def() { return defense; }

  int get_enemy_lvl() { return level; }

  int get_enemy_exp() { return giveExp; }
    
  int get_enemy_coin() {return giveCoin;}
    
  void set_enemy_atk(int attack) {this->attack = attack;}
    
  void set_enemy_def(int defense) {this->defense = defense;}
    
  void set_enemy_hp(int value) { currHP -= value; }
  
  characterType getcharType() const { return role; }

  characterType setRole(characterType newRole) { return newRole; }

  void levelUp() override {}
  
  string NameMaker() override {
    string name = "Enemy";
    return name;
  }
};

#endif  //__Enemy_H__
