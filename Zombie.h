//
//  Zombie.h
//  
//
//  Created by Lilia Rouhi on 12/21/1402 AP.
//

#ifndef Zombie_h
#define Zombie_h


class Zombie : public Character
{
public :
    Zombie() ;
    virtual int attack_func(Human* curenemy);
    virtual void takeDamage();
};


#endif /* Zombie_h */
