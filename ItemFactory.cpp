#include "ItemFactory.h"
#include <iostream>

Item* ItemFactory::createItem(int choice, Human *human) {

    Item *item = nullptr;
    string name, perk, type;
    bool VIP;
    double synergyDamage, price;
    int count, number;
    switch (choice)
    {
        case 1:
            item = new Armor(name, price, VIP, perk, type, synergyDamage, count);
            break;
        case 2:
            item = new Shield(name, price, VIP, perk, type, synergyDamage, count);
            break;
        case 3:
            item = new MagicShield(name, price, VIP, perk, type, synergyDamage, count);
            break;
        case 4:
            item = new IronBody(name, price, VIP, perk, type, synergyDamage, count);
            break;
        case 5:
            item = new BulletproofJacket(name, price, VIP, perk, type, synergyDamage, count);
            break;
        case 6:
            item = new Cloak(name, price, VIP, perk, type, synergyDamage, count);
            break;
        case 7:
            item = new PersianDad(name, price, VIP, perk, type, synergyDamage, count);
            break;
        case 8:
            item = new Sword(name, price, VIP, perk, type, synergyDamage, count);
            break;
        case 9:
            item = new Spear(name, price, VIP, perk, type, synergyDamage, count);
            break;
        case 10:
            item = new Katana(name, price, VIP, perk, type, synergyDamage, count);
            break;
        case 11:
            item = new PoisonDagger(name, price, VIP, perk, type, synergyDamage, count);
            break;
        case 12:
            item = new Wand(name, price, VIP, perk, type, synergyDamage, count);
            break;
        case 13:
            item = new Book(name, price, VIP, perk, type, synergyDamage, count);
            break;
        case 14:
            item = new LaserGun(name, price, VIP, perk, type, synergyDamage, count);
            break;
        case 15:
            item = new LittleRobots(name, price, VIP, perk, type, synergyDamage, count);
            break;
        case 16:
            item = new Snipe(name, price, VIP, perk, type, synergyDamage, count);
            break;
        case 17:
            item = new Colt(name, price, VIP, perk, type, synergyDamage, count);
            break;
        case 18:
            item = new EyeLaser(name, price, VIP, perk, type, synergyDamage, count);
            break;
        case 19:
            item = new WhipOfTruth(name, price, VIP, perk, type, synergyDamage, count);
            break;
        case 20:
            item = new Swatter(name, price, VIP, perk, type, synergyDamage, count);
            break;
        case 21:
            item = new Pepper(name, price, VIP, perk, type, synergyDamage, count);
            break;
        case 22:
            item = new Bow(name, price, VIP, synergyDamage, count);
            if (item != nullptr) {
                Shop shop;
                shop.buyItemWithCountLimit(choice, human, item, 5);
            }
            break;
        case 23:
            item = new NinjaStar(name, price, VIP, synergyDamage, count);
            if (item != nullptr) {
                Shop shop;
                shop.buyItemWithCountLimit(choice, human, item, 5);
            }
            break;
        case 24:
            item = new FireBall(name, price, VIP, synergyDamage, count);
            if (item != nullptr) {
                Shop shop;
                shop.buyItemWithCountLimit(choice, human, item, 5);
            }
            break;
        case 25:
            item = new Rocket(name, price, VIP, number, synergyDamage, count);
            if (item != nullptr) {
                Shop shop;
                shop.buyItemWithCountLimit(choice, human, item, 5);
            }
            break;
        case 26:
            item = new Grenade(name, price, VIP, synergyDamage, count);
            if (item != nullptr) {
                Shop shop;
                shop.buyItemWithCountLimit(choice, human, item, 5);
            }
            break;
        case 27:
            item = new SpiderNet(name, price, VIP, synergyDamage, count);
            if (item != nullptr) {
                Shop shop;
                shop.buyItemWithCountLimit(choice, human, item, 5);
            }
            break;
        case 28:
            item = new Flipflops(name, price, VIP, synergyDamage, count);
            if (item != nullptr) {
                Shop shop;
                shop.buyItemWithCountLimit(choice, human, item, 5);
            }
            break;
        case 29:
            item = new HealingPotion(name, price, VIP, synergyDamage, count);
            if (item != nullptr) {
                Shop shop;
                shop.buyItemWithCountLimit(choice, human, item, 5);
            }
            break;
        case 30:
            item = new DamagePotion(name, price, VIP, synergyDamage, count);
            if (item != nullptr) {
                Shop shop;
                shop.buyItemWithCountLimit(choice, human, item, 5);
            }
            break;
        case 31:
            item = new DefensePotion(name, price, VIP, synergyDamage, count);
            if (item != nullptr) {
                Shop shop;
                shop.buyItemWithCountLimit(choice, human, item, 5);
            }
            break;
        case 32:
            item = new StaminaPotion(name, price, VIP, synergyDamage, count);
            if (item != nullptr) {
                Shop shop;
                shop.buyItemWithCountLimit(choice, human, item, 5);
            }
            break;
        case 33:
            item = new Food(name, price, VIP, synergyDamage, count);
            if (item != nullptr) {
                Shop shop;
                shop.buyItemWithCountLimit(choice, human, item, 5);
            }
            break;
        case 34:
            item = new SweetTea(name, price, VIP, synergyDamage, count);
            if (item != nullptr) {
                Shop shop;
                shop.buyItemWithCountLimit(choice, human, item, 5);
            }
            break;
        case 35:
            item = new Saffron(name, price, VIP, synergyDamage, count);
            if (item != nullptr) {
                Shop shop;
                shop.buyItemWithCountLimit(choice, human, item, 5);
            }
            break;
        case 36:
            item = new AraghNana(name, price, VIP, synergyDamage, count);
            if (item != nullptr) {
                Shop shop;
                shop.buyItemWithCountLimit(choice, human, item, 5);
            }
            break;
        case 37:
            item = new Nuts(name, price, VIP, synergyDamage, count);
            if (item != nullptr) {
                Shop shop;
                shop.buyItemWithCountLimit(choice, human, item, 5);
            }
        default:
            cout << "Invalid choice." << endl;
    }
    return item;
}