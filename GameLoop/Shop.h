#ifndef SHOP_H
#define SHOP_H

#include "../Characters/Character.h"
#include "../Characters/Humans/Human.h"
#include "../Items/Item.h"
#include "../Items/Passive.h"
#include "../Items/AraghNana.h"
#include "../Items/Armor.h"
#include "../Items/Book.h"
#include "../Items/Bow.h"
#include "../Items/BulletproofJacket.h"
#include "../Items/Cloak.h"
#include "../Items/Colt.h"
#include "../Items/Consumable.h"
#include "../Items/DamagePotion.h"
#include "../Items/DefensePotion.h"
#include "../Items/EyeLaser.h"
#include "../Items/FireBall.h"
#include "../Items/Flip_flops.h"
#include "../Items/Food.h"
#include "../Items/Grenade.h"
#include "../Items/HealingPotion.h"
#include "../Items/IronBody.h"
#include "../Items/Katana.h"
#include "../Items/LaserGun.h"
#include "../Items/LittleRobots.h"
#include "../Items/MagicShield.h"
#include "../Items/NinjaStar.h"
#include "../Items/Nuts.h"
#include "../Items/Pepper.h"
#include "../Items/PersianDad.h"
#include "../Items/PoisonDagger.h"
#include "../Items/Rocket.h"
#include "../Items/Saffron.h"
#include "../Items/Shield.h"
#include "../Items/Snipe.h"
#include "../Items/Spear.h"
#include "../Items/SpiderNet.h"
#include "../Items/StaminaPotion.h"
#include "../Items/Swatter.h"
#include "../Items/SweetTea.h"
#include "../Items/Sword.h"
#include "../Items/Throwable.h"
#include "../Items/Wand.h"
#include "../Items/WhipOfTruth.h"


class Shop{
public:
    Shop();

    void showShop();

    void buyItem(Human *human);
    
    void buyItemWithCountLimit(int choice, Human* human, Item* item, int maxCount);

    void buy (int choice, Human* human);
    
    void sell(Human* human);
    
    void welcomShop(Human* human);
    
};


#endif /* SHOP_H */
