#ifndef HUMANENEMY_H
#define HUMANENEMY_H

#include "Enemy.h"
#include "Character.h"
#include "Human.h"
#include "CharacterType.h"

class HumanEnemy : public Enemy
{
public:
    HumanEnemy(Human &humanRef);

    HumanEnemy(int level, Human &humanRef);

    HumanEnemy(int level, Human &human, Human &humanRef);

    virtual int attackChar(double charDefense) override;
    characterType getRandomRole();
    void setRoleBasedOnHuman(Human &humanref);

    virtual void performAttack(Character &target)
    {
        humanRef.performAttack(target);
    }

    virtual void performDefense(Enemy &attacker)
    {
        humanRef.performDefense(attacker);
    }

    // Items Functions
    // void showEquipments() { human.showEquipments(); }
    // void showConsumables() { human.showConsumables(); }
    // void addInventory(Items *item) { human.addInventory(item); }
    // void removeInventory(int index) { human.removeInventory(index); }
    // int inventorySize() { return human.inventorySize(); }
    // Items *itemsAt(int index) { return human.itemsAt(index); }
    // Items *getArmor() { return human.getArmor(); }
    // Items *getWeapon() { return human.getWeapon(); }

private:
    Human &humanRef;
};

#endif /* HUMANENEMY_H */
