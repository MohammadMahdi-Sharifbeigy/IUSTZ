//
//  Paladin.h
//  
//
//  Created by Lilia Rouhi on 12/21/1402 AP.
//

#ifndef Paladin_h
#define Paladin_h


class Paladin : public Human
{
public :
    Paladin(string name , int age);

    virtual int attack_func (Human * currEnemy , Item* item) override ;
    
    virtual int attack_func (Character * currEnemy , Item* item) override ;
    
    virtual void takeDamage(int damage) override;
    
    virtual void levelUp() override ;
    
};

#endif /* Paladin_h */
