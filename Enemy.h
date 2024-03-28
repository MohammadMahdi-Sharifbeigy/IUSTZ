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
    hp = getRandomNumber(characterLevel, characterLevel + 10) + 100;
    giveExp = level * 10 * attack / defense;
    // attack = getRandomNumber(characterLevel, characterLevel + 10) + 10;
  }

 protected:
  int hp;
  int attack;
  int defense;
  int level;
  int giveExp;
  characterType role;

 public:
  virtual void takeDamage(double amount) override {
    hp -= amount;
    if (hp < 0) {
      hp = 0;
    }
  };

  int get_enemy_hp() { return hp; }

  int get_enemy_atk() { return attack; }

  int get_enemy_def() { return defense; }

  int get_enemy_lvl() { return level; }

  int get_enemy_exp() { return giveExp; }

  void set_enemy_hp(int value) { hp -= value; }
  characterType getcharType() const { return role; }
  characterType setRole(characterType newRole) { return newRole; }
  void levelUp() override {
    level++;
    hp += 10;
    attack += 5;
    defense += 5;
    giveExp = level * 10 * attack / defense;
  }
  string NameMaker() override {
    string name = "Enemy";
    return name;
  }
  virtual double attackChar(double charDefense) {
    return abs((((((2 * level / 5) + 2) * (35 + (level * 9 / 10)) * attack) /
                 charDefense) /
                50) +
               2);
  }
};

#endif  //__Enemy_H__