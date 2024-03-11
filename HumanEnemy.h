//
//  HumanEnemy.h
//  
//
//  Created by Lilia Rouhi on 12/21/1402 AP.
//

#ifndef HumanEnemy_h
#define HumanEnemy_h


class HumanEnemy : public Human
{
public :
    HumanEnemy(Human* human);
    
    virtual int attack_func (Character * currEnemy , Item* item);
    
    virtual void takeDamage(int damage) override;
};

#endif /* HumanEnemy_h */
