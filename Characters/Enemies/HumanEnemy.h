#ifndef HUMANENEMY_H
#define HUMANENEMY_H

#include "Enemy.h"
#include "HumanEnemyAttack.h"
#include "State.h"
#include "EnemyFactory.h"
#include "../Humans/Human.h"
#include "../../Items/ItemFactory.h"
#include "../Character.h"
#include "../CharacterType.h"

// Model
class HumanEnemyModel : public Enemy {

public:
    HumanEnemyModel(int level, Human& humanRef);

    HumanEnemyModel(int level, Human& human, Human& humanRef);

    ~HumanEnemyModel();
  
    characterType getRandomRole();

    void setRoleBasedOnHuman(Human& humanref);

    void performAttack(Character& target);

    void performDefense(Human& attacker);

    State getState();

    void setState(State state);
    
    void setStateBasedOnHP();
    
    bool useHealingPotion();
    
    bool useAttackPotion();
    
    bool useDefensePotion();
    
    double useAtkItem (bool dontUse);
    
    double useDefItem(bool dontUse);
    
    void atkInUpdate(Human &target , bool dont);
    
    void defInUpdate(Human &target , bool dont);
    
    void Update(Human &target);

    // Items Functions
    void showInventory() { humanRef.showInventory(); }
    void addInventory(Item* item) { humanRef.addInventory(item); }
    void addInventory(Item* item, int count){humanRef.addInventory(item, count); }
    void removeInventory(int index, int count) {humanRef.removeInventory(index, count); }
    void removeInventory(int index) { humanRef.removeInventory(index); }
    int inventorySize() { return humanRef.inventorySize(); }
    bool existInInventory(Item* item){return humanRef.existInInventory(item); }
    int countInInventory(Item* item){return humanRef.countInInventory(item); }
    int indexInInventory(Item* item){return humanRef.indexInInventory(item); }
    double priceItemsAt(int index){return humanRef.priceItemsAt(index); }
    int countItemsAt(int index){return humanRef.countItemsAt(index); }
    Item* itemsAt(int index) { return humanRef.itemsAt(index); }
    Item* getArmor() { return humanRef.getArmor(); }
    Item* getWeapon() { return humanRef.getWeapon(); }
    void setArmor(Item* armor){return humanRef.setArmor(armor); }
    void setWeapon(Item* weapon){return humanRef.setWeapon(weapon); }
    Item* stringToItem(const string& line){return humanRef.stringToItem(line); }

private:
    Human& humanRef;
    AttackStrategy* attackStrategy;
    State state;
    bool haveUsedAtkP;
    bool haveUsedDefP;
    vector<Item*> inventory;
};

//view
class HumanEnemyView {
public:
    HumanEnemyView();

    void displayHumanEnemy(HumanEnemyModel* humanEnemy);
};

// Controller
class HumanEnemyController {
public:
    HumanEnemyController(HumanEnemyModel& model, HumanEnemyView& view);

    void PerformAttack(Character& target);

    void PerformDefense(Human& attacker);
private:
    HumanEnemyModel& model;
    HumanEnemyView& view;
};

#endif /* HUMANENEMY_H */
