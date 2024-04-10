#ifndef STRONGZOMBIE_H
#define STRONGZOMBIE_H

#include <iostream>
#include <cstdlib>
#include "Enemy.h"
#include "EnemyFactory.h"
#include "../Fonts/font.h"
#include "../Humans/Human.h"
#include "../Character.h"
#include "../CharacterType.h"

class StrongZombie : public Enemy {
 public:
  StrongZombie();
  StrongZombie(int level);
};

class StrongZombieModel {
 public:
  StrongZombieModel();
  StrongZombie* createStrongZombie(int level, Human* human);
};

class StrongZombieView {
 public:
  StrongZombieView();
  void displayStrongZombie(StrongZombie* strongZombie);
};

class StrongZombieController {
 public:
  StrongZombieController(StrongZombieModel* model, StrongZombieView* view);
  void createAndDisplayStrongZombie(int level, Human* human);
 private:
  StrongZombieModel* model;
  StrongZombieView* view;
};

#endif /* STRONGZOMBIE_H */
