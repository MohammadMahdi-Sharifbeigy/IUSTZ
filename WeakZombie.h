#ifndef WEAKZOMBIE_H
#define WEAKZOMBIE_H

#include "Character.h"
#include "CharacterType.h"
#include "Enemy.h"
#include "Human.h"

class WeakZombie : public Enemy {
 public:
  WeakZombie();

  WeakZombie(int level);

};
#endif /* WEAKZOMBIE_H */