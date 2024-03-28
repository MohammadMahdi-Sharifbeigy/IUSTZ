#ifndef Enemy_FACTORY_H
#define Enemy_FACTORY_H

#include "Enemy.h"
#include "Human.h"
#include "WeakZombie.h"
#include "StrongZombie.h"
#include "HumanEnemy.h"

class EnemyFactory : public Enemy {
public:
    static Enemy* CreatEnemy(characterType type, const string& name, int age, double hp, double attack, double defense, int level) {
        switch (type) {
            case WEAKZOMBIE:
                return new WeakZombie(level);
                break;
            case STRONGZOMBIE:
                return new StrongZombie(level);
                break;
            default:
                return nullptr;
        }
    }
};

#endif  // HUMAN_FACTORY_H
