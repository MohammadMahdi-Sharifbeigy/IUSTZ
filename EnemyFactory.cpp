//
//  EnemyFactory.cpp
//  
//
//  Created by Lilia Rouhi on 1/12/1403 AP.
//


#include "EnemyFactory.h"


using namespace std;


    static Enemy *createEnemy(characterType type, int level, Human *humanRef = nullptr)
{
        switch (type)
        {
            case HUMANENEMY:
                if (humanRef)
                {
                    
                    return new HumanEnemy(level, *humanRef);
                }
                else
                {
                    // Handle default behavior when humanRef is not provided
                    // return new HumanEnemy(level, /* Provide default Human object */);
                }
            case WEAKZOMBIE:
                return new WeakZombie(level);
            case STRONGZOMBIE:
                return new StrongZombie(level);
            default:
                return nullptr;
        }
        
    }
        
        static Enemy *createEnemy(characterType type, int level,Human* human, Human *humanRef = nullptr)
        {
            switch (type)
            {
            case HUMANENEMY:
                if (humanRef)
                {
                    
                   return new HumanEnemy(level,*human, *humanRef);
                }
                else
                {
                    // Handle default behavior when humanRef is not provided
                    // return new HumanEnemy(level, /* Provide default Human object */);
                }
            case WEAKZOMBIE:
                return new WeakZombie(level);
            case STRONGZOMBIE:
                return new StrongZombie(level);
            default:
                return nullptr;
            }
        
        
        
    }
            
            
            
            

