#ifndef HUMANENEMY_H
#define HUMANENEMY_H

#include "Character.h"
#include "CharacterType.h"
#include "Enemy.h"
#include "HumanEnemyAttack.h"
#include "Human.h"
#include "ItemFactory.h"
#include "State.h"
#include "EnemyFactory.h"

class HumanEnemy : public Enemy {
public:
  

  HumanEnemy(int level, Human& humanRef);

  HumanEnemy(int level, Human& human, Human& humanRef);

  ~HumanEnemy();
  
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

#endif /* HUMANENEMY_H */
