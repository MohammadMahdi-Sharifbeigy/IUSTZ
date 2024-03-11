//
//  Assasin.h
//  
//
//  Created by Lilia Rouhi on 12/21/1402 AP.
//

#ifndef Assasin_h
#define Assasin_h


class Assasin : public Human
{
public :
    Assasin(string name , int age) ;

    virtual int attack_func (Human * currEnemy , Item* item) override ;
    
    virtual int attack_func (Character * currEnemy , Item* item) override ;
    
    virtual void takeDamage(int damage) override;
    
    virtual void levelUp() override ;
    
};


#endif /* Assasin_h */
