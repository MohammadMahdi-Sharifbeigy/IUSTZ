//
//  Human.h
//  bardia dar hezardastan
//
//  Created by Lilia Rouhi on 12/21/1402 AP.
//

#ifndef Human_h
#define Human_h



class Human : public Character
{
protected :
    int age;
    int maxXP;
    int currXP;
    double stamin;
    double strenght;
    double endurance;
    double accuracy;
    double pace;
    double mind;
    int coin;
    Item* chestArmor;
    Item* weapon;
    Item* leggings;
    Item* helmet;
    vector<Item*> consumables;
    vector<Item*> equipment;
    virtual int attack_func(Human* curenemy , Item* item);
    virtual int attack_func(Character* curenemy , Item* item);
    virtual void takeDamage(int damage);
public :
    Human() = default;
    
    Human(string name,string role , int age);
    virtual string NameMaker() override;
    void firearm_ability();
    void coldweapon_ability();
    void addEquipments(Item* newEquipment);
    void addConsumables(Item* newConsumable);
    void showEquipments();
    void showConsumables();
    virtual void levelUp();
    int getAge();
    void setName(int age);
    int getCurrXP ();
    void setCurrXP (int currXP);
    int getMaxXP ();
    void setMaxXP (int maxXP);
    double getStamin();
    void setStamin(double stamin);
    double getStrenght ();
    void setStrenght (double strenght);
    double getEndurance ();
    void setEndurance (double endurance);
    double getAccuracy();
    void setAccuracy(double accuracy);
    double getPace ();
    void setPace (double pace);
    double getMind ();
    void setMind (double mind);
    int getCoin();
    void setCoin(int coin);
    Item* getChestArmor ();
    void setChestArmor (Item* chestArmor);
    Item* getWeapon ();
    void setWeapon (Item* weapon);
    Item* getLeggings ();
    void setLeggings (Item* leggings);
    Item* getHelmet ();
    void setHelmet (Item* helmet);
};






#endif /* Human_h */
