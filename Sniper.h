//
//  Sniper.h
//  
//
//  Created by Lilia Rouhi on 12/21/1402 AP.
//

#ifndef Sniper_h
#define Sniper_h


class Sniper : public Human
{
public :
    Sniper(string name , int age) ;

    virtual int attack_func (Human * currEnemy , Item* item) override;
    
    virtual int attack_func (Character * currEnemy , Item* item) override ;
    
    virtual void takeDamage(int damage) override;
    
    virtual void levelUp() override;
    
};

#endif /* Sniper_h */
