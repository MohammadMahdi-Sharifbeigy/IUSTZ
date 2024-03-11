//
//  SuperHero.h
//  
//
//  Created by Lilia Rouhi on 12/21/1402 AP.
//

#ifndef SuperHero_h
#define SuperHero_h


class SuperHero : public Human
{
public :
    SupeHero(string name , int age);

    virtual int attack_func (Human * currEnemy , Item* item) override ;
    
    virtual int attack_func (Character * currEnemy , Item* item) override ;
    
    virtual void takeDamage(int damage) override;
    
    virtual void levelUp() override ;
    
};


#endif /* SuperHero_h */
