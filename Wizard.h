//
//  Wizard.h
//  
//
//  Created by Lilia Rouhi on 12/21/1402 AP.
//

#ifndef Wizard_h
#define Wizard_h


class Wizard : public Human
{
public :
    Wizard(string name , int age);

    virtual int attack_func (Human * currEnemy , Item* item) override;
    
    virtual int attack_func (Character * currEnemy , Item* item) override;
    
    virtual void takeDamage(int damage) override;
    
    
    virtual void levelUp() override ;
    
};


#endif /* Wizard_h */
