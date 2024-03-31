#ifndef Enemy_FACTORY_H
#define Enemy_FACTORY_H

#include "Enemy.h"
#include "Human.h"
#include "WeakZombie.h"
#include "StrongZombie.h"
#include "HumanEnemy.h"


class EnemyFactory
{
public:
    static Enemy *createEnemy(characterType type, int level, Human *humanRef = nullptr);
        
    static Enemy *createEnemy(characterType type, int level,Human* human, Human *humanRef = nullptr);
        
        
};
            
            
            
            


#endif  // HUMAN_FACTORY_H
