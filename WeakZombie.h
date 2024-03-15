#ifndef WEAKZOMBIE_H
#define WEAKZOMBIE_H

#include "Enemy.h"
#include "Character.h"
#include "Human.h"
#include "CharacterType.h"

class WeakZombie : public Enemy
{
public:
    WeakZombie();

    WeakZombie(int level);
 
    virtual int attackChar(double charDefense) override;
};
#endif /* WEAKZOMBIE_H */