#ifndef HUMANENEMY_H
#define HUMANENEMY_H

#include "Enemy.h"
#include "Character.h"
#include "Human.h"
#include "CharacterType.h"

class HumanEnemy : public Enemy
{
public:
    HumanEnemy();

    HumanEnemy(int level);

    HumanEnemy(int level, Human &human);

    virtual int attackChar(double charDefense) override;

    characterType getRandomRole();

    void setRoleBasedOnHuman(Human &human);
};

#endif /* HUMANENEMY_H */

