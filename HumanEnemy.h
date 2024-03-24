#ifndef HUMANENEMY_H
#define HUMANENEMY_H

#include "Character.h"
#include "CharacterType.h"
#include "Enemy.h"
#include "HumanEnemyAttack.h"
#include "Human.h"

class HumanEnemy : public Enemy {
 public:
  HumanEnemy(Human& humanRef);

  HumanEnemy(int level, Human& humanRef);

  HumanEnemy(int level, Human& human, Human& humanRef);

  ~HumanEnemy();

  virtual double attackChar(double charDefense) override;
  
  characterType getRandomRole();

  void setRoleBasedOnHuman(Human& humanref);

  void performAttack(Character& target);

  void performDefense(Human& attacker);

  // Items Functions
  void showInventory() { humanRef.showInventory(); }
  void addInventory(Item* item) { humanRef.addInventory(item); }
  void removeInventory(int index) { humanRef.removeInventory(index); }
  int inventorySize() { return humanRef.inventorySize(); }
  Item* itemsAt(int index) { return humanRef.itemsAt(index); }
  Item* getArmor() { return humanRef.getArmor(); }
  Item* getWeapon() { return humanRef.getWeapon(); }

 private:
  Human& humanRef;
  AttackStrategy* attackStrategy;
};

#endif /* HUMANENEMY_H */
