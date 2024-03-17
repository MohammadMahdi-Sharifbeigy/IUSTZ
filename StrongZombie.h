#ifndef STRONGZOMBIE_H
#define STRONGZOMBIE_H

#include "Character.h"
#include "CharacterType.h"
#include "Enemy.h"
#include "Human.h"

class StrongZombie : public Enemy {
 public:
  StrongZombie();

  StrongZombie(int level);

  virtual double attackChar(double charDefense) override;
};

#endif /* STRONGZOMBIE_H */