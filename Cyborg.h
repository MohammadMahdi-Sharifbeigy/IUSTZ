//
//  Cyborg.h
//  
//
//  Created by Lilia Rouhi on 12/21/1402 AP.
//

#ifndef Cyborg_h
#define Cyborg_h



class Cyborg : public Human
{
public :
    Cyborg(string name , int age) ;

    virtual int attack_func (Human * currEnemy , Item* item) override ;
    
    virtual int attack_func (Character * currEnemy , Item* item) override ;
    
    virtual void takeDamage(int damage) override;
    
    virtual void levelUp() override;
    
};

#endif /* Cyborg_h */
