//
//  AsianMom.h
//  
//
//  Created by Lilia Rouhi on 12/21/1402 AP.
//

#ifndef AsianMom_h
#define AsianMom_h


class AsianMom : public Human
{
public :
    AsianMom(string name , int age) ;

    virtual int attack_func (Human * currEnemy , Item* item) override;
    
    virtual int attack_func (Character * currEnemy , Item* item) override ;
    
    virtual void takeDamage(int damage) override;
    
    virtual void levelUp() override ;
};



#endif /* AsianMom_h */
