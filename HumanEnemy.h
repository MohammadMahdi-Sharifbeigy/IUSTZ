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

// Model
class HumanEnemyModel : public Enemy {
public:
    explicit HumanEnemyModel(int level, Human& human);

    ~HumanEnemyModel();

    characterType getRandomRole();

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
    void showInventory();
    void addInventory(Item* item);
    void addInventory(Item* item, int count);
    void removeInventory(int index, int count);
    void removeInventory(int index);
    int inventorySize();
    bool existInInventory(Item* item);
    int countInInventory(Item* item);
    int indexInInventory(Item* item);
    double priceItemsAt(int index);
    int countItemsAt(int index);
    Item* itemsAt(int index);

private:
    Human& human;
    AttackStrategy* attackStrategy;
    State state;
    bool haveUsedAtkP;
    bool haveUsedDefP;
    vector<Item*> inventory;
};

// View
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
