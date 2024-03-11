//
//  Character.h
//  
//
//  Created by Lilia Rouhi on 12/21/1402 AP.
//

#ifndef Character_h
#define Character_h


class Character
{
protected :
    string name;
    double maxHP;
    double currHP;
    int level;
    string role;
    int attack;
    int defense;
    Character();
public :
    virtual string NameMaker();
    string getName();
    void setName(string name);
    int getCurrHP ();
    void setCurrHP (int currHp);
    int getMaxHP ();
    void setMaxHP (int maxHP);
    int getLevel ();
    void setLevel(int level);
    string getRole();
    void setRole(string role);
    int getAttack ();
    void setAttack (int attack);
    int getDefense ();
    void setDefense (int defense);
};






#endif /* Character_h */
