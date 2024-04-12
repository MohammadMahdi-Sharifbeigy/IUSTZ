#ifndef SHOP_H
#define SHOP_H

#include "AraghNana.h"
#include "Armor.h"
#include "Book.h"
#include "Bow.h"
#include "BulletproofJacket.h"
#include "Character.h"
#include "CheckNumber.h"
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
#include "Human.h"
#include "IronBody.h"
#include "Item.h"
#include "Katana.h"
#include "LaserGun.h"
#include "LittleRobots.h"
#include "MagicShield.h"
#include "NinjaStar.h"
#include "Nuts.h"
#include "Passive.h"
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

class Shop {
 public:
  Shop();

  void showShop();

  void buyItem(Human* human);

  void buyItemWithCountLimit(int choice,
                             Human* human,
                             Item* item,
                             int maxCount);

  void buy(int choice, Human* human);

  void sell(Human* human);

  void welcomeShop(Human* human);
};

#endif /* SHOP_H */
