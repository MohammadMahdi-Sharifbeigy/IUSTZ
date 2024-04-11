#ifndef WEAKZOMBIE_H
#define WEAKZOMBIE_H

#include <iostream>
#include <cstdlib>
#include "Enemy.h"
#include "EnemyFactory.h"
#include "../../Fonts/font.h"
#include "../Humans/Human.h"
#include "../Character.h"
#include "../CharacterType.h"

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
