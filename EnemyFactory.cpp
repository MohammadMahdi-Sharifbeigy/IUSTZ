#include "EnemyFactory.h"

using namespace std;

Enemy* EnemyFactory::createEnemy(characterType type, int level, Human *humanRef){
    switch (type){
        case HUMANENEMY:
            if (humanRef){                    
                return new HumanEnemy(level, *humanRef);
            }
        break;
        case WEAKZOMBIE:
            return new WeakZombie(level);
        case STRONGZOMBIE:
            return new StrongZombie(level);
        default:
            return nullptr;
    }        
}

Enemy* EnemyFactory::createEnemy(characterType type, int level,Human* human, Human *humanRef = nullptr){
    switch (type){
        case HUMANENEMY:
            if (humanRef){                
               return new HumanEnemy(level,*human, *humanRef);
            }
        break;
        case WEAKZOMBIE:
            return new WeakZombie(level);
        case STRONGZOMBIE:
            return new StrongZombie(level);
        default:
            return nullptr;
    }
}
