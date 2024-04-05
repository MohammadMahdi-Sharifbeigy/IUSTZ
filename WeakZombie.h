#ifndef WEAKZOMBIE_H
#define WEAKZOMBIE_H

#include "Character.h"
#include "CharacterType.h"
#include "Enemy.h"
#include "Human.h"
#include "EnemyFactory.h"
#include <iostream>
#include <cstdlib>

class WeakZombie : public Enemy {
 public:
  WeakZombie();
  WeakZombie(int level);
};

class WeakZombieModel {
 public:
  WeakZombieModel();
  WeakZombie* createWeakZombie(int level, Human* human);
};

class WeakZombieView {
 public:
  WeakZombieView();
  void displayWeakZombie(WeakZombie* weakZombie);
};

class WeakZombieController {
 public:
  WeakZombieController(WeakZombieModel* model, WeakZombieView* view);
  void createAndDisplayWeakZombie(int level, Human* human);
 private:
  WeakZombieModel* model;
  WeakZombieView* view;
};

#endif /* WEAKZOMBIE_H */
