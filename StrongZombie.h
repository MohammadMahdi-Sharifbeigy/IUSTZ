#ifndef STRONGZOMBIE_H
#define STRONGZOMBIE_H

#include "Enemy.h"
#include "Character.h"
#include "Human.h"
#include "CharacterType.h"

class StrongZombie : public Enemy
{
public:
    StrongZombie();

    StrongZombie(int level);

    virtual int attackChar(double charDefense) override;
};

#endif /* STRONGZOMBIE_H */