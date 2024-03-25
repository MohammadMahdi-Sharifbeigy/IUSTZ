//
//  Shop.h
//  
//
//  Created by Lilia Rouhi on 1/5/1403 AP.
//

#ifndef Shop_h
#define Shop_h
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
#include "Counsumable.h"
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
#include "AsianDad.h"
#include "PoisonDagger.h"
#include "Rocket.h"
#include "Saffron.h"
#include "Shield.h"
#include "Snipe.h"
#include "Spear.h"
#include "SpideNet.h"
#include "StaminPotion.h"
#include "Swatter.h"
#include "SweetTea.h"
#include "Sword.h"
#include "Throwable.h"
#include "Wand.h"
#include "WhipOfTruth.h"
#include "CheckNumber.h"


class Shop{
public:
    Shop() = default;
    void showShop();
    
    void buy (Human* human);
    
    void sell(Human* human);
    
    void welcom(Human* human);
    
};


#endif /* Shop_h */
