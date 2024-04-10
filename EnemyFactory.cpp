#include "EnemyFactory.h"

using namespace std;

Enemy* EnemyFactory::createEnemy(characterType type, int level,Human* human){
    switch (type){
        case HUMANENEMY:
            if (human){                
               return new HumanEnemyModel(level,*human);
            }
        break;
        case WEAKZOMBIE:
            return new WeakZombie(level);
        case STRONGZOMBIE:
            return new StrongZombie(level);
        default:
            return nullptr;
    }
    return nullptr;
}
