//
//  StrongZombie.h
//  
//
//  Created by Lilia Rouhi on 12/21/1402 AP.
//

#ifndef StrongZombie_h
#define StrongZombie_h


class StrongZombie : public Zombie
{
public :
    StrongZombie(Human* human);
    virtual int attack_func(Human* curenemy);
    virtual void takeDamage();
    
};

#endif /* StrongZombie_h */
