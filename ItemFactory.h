#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include "Character.h"
#include "Human.h"
#include "Item.h"
#include "Passive.h"
#include "AraghNana.h"
#include "Armor.h"
#include "Book.h"
#include "Bow.h"
#include "BulletproofJacket.h"
#include "Cloak.h"
#include "Colt.h"
#include "Consumable.h"
#include "DamagePotion.h"
#include "DefensePotion.h"
#include "EyeLaser.h"
#include "FireBall.h"
#include "Flip_flops.h"
#include "Food.h"
#include "Grenade.h"
#include "HealingPotion.h"
#include "IronBody.h"
#include "Katana.h"
#include "LaserGun.h"
#include "LittleRobots.h"
#include "MagicShield.h"
#include "NinjaStar.h"
#include "Nuts.h"
#include "Pepper.h"
#include "PersianDad.h"
#include "PoisonDagger.h"
#include "Rocket.h"
#include "Saffron.h"
#include "Shield.h"
#include "Snipe.h"
#include "Spear.h"
#include "SpiderNet.h"
#include "StaminaPotion.h"
#include "Swatter.h"
#include "SweetTea.h"
#include "Sword.h"
#include "Throwable.h"
#include "Wand.h"
#include "WhipOfTruth.h"
#include "CheckNumber.h"
#include "Shop.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <random>

class ItemFactory{
public:
    ItemFactory() =  default;
    static Item *createItem(int choice, Human *human, bool login);
    static Item *createItemInventory(int id);
};

#endif /* ITEMFACTORY_H */
