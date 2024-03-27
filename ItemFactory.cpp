#include "ItemFactory.h"
#include <iostream>
#include <string>
using namespace std;

Item* ItemFactory::createItem(int choice, Human* human) {
  Item* item = nullptr;
  string name, perk = "Default Perk", type = "Default Type";
  bool VIP = false;
  double synergyDamage = 10.0, price = 100.0;
  int count = 1, number = 1;

  switch (choice) {
    case 1:
      name = "Fortified Armor";
      price = 150.0;
      item = new Armor(name, price, VIP, perk, type, synergyDamage, count);
      break;
    case 2:
      name = "Defender's Shield";
      price = 120.0;
      item = new Shield(name, price, VIP, perk, type, synergyDamage, count);
      break;
    case 3:
      name = "Mystic Magic Shield";
      price = 200.0;
      item =
          new MagicShield(name, price, VIP, perk, type, synergyDamage, count);
      break;
    case 4:
      name = "Titan Iron Body";
      price = 250.0;
      item = new IronBody(name, price, VIP, perk, type, synergyDamage, count);
      break;
    case 5:
      name = "Guardian Bulletproof Jacket";
      price = 180.0;
      item = new BulletproofJacket(name, price, VIP, perk, type, synergyDamage,
                                   count);
      break;
    case 6:
      name = "Shadow Cloak";
      price = 160.0;
      item = new Cloak(name, price, VIP, perk, type, synergyDamage, count);
      break;
    case 7:
      name = "Persian Royal Dad";
      price = 300.0;
      item = new PersianDad(name, price, VIP, perk, type, synergyDamage, count);
      break;
    case 8:
      name = "Blade of Valor";
      price = 110.0;
      item = new Sword(name, price, VIP, perk, type, synergyDamage, count);
      break;
    case 9:
      name = "Spear of Destiny";
      price = 115.0;
      item = new Spear(name, price, VIP, perk, type, synergyDamage, count);
      break;
    case 10:
      name = "Windwalker Katana";
      price = 220.0;
      item = new Katana(name, price, VIP, perk, type, synergyDamage, count);
      break;
    case 11:
      name = "Venomous Poison Dagger";
      price = 130.0;
      item =
          new PoisonDagger(name, price, VIP, perk, type, synergyDamage, count);
      break;
    case 12:
      name = "Arcane Wand";
      price = 140.0;
      item = new Wand(name, price, VIP, perk, type, synergyDamage, count);
      break;
    case 13:
      name = "Book of Secrets";
      price = 90.0;
      item = new Book(name, price, VIP, perk, type, synergyDamage, count);
      break;
    case 14:
      name = "Photon Laser Gun";
      price = 210.0;
      item = new LaserGun(name, price, VIP, perk, type, synergyDamage, count);
      break;
    case 15:
      name = "Miniature Combat Robots";
      price = 310.0;
      item =
          new LittleRobots(name, price, VIP, perk, type, synergyDamage, count);
      break;
    case 16:
      name = "Silent Snipe";
      price = 250.0;
      item = new Snipe(name, price, VIP, perk, type, synergyDamage, count);
      break;
    case 17:
      name = "Classic Colt Revolver";
      price = 170.0;
      item = new Colt(name, price, VIP, perk, type, synergyDamage, count);
      break;
    case 18:
      name = "Cyclopean Eye Laser";
      price = 280.0;
      item = new EyeLaser(name, price, VIP, perk, type, synergyDamage, count);
      break;
    case 19:
      name = "Truth's Whip";
      price = 150.0;
      item =
          new WhipOfTruth(name, price, VIP, perk, type, synergyDamage, count);
      break;
    case 20:
      name = "Giant Swatter";
      price = 60.0;
      item = new Swatter(name, price, VIP, perk, type, synergyDamage, count);
      break;
    case 21:
      name = "Fiery Pepper Spray";
      price = 40.0;
      item = new Pepper(name, price, VIP, perk, type, synergyDamage, count);
      break;
    case 22:
      name = "Ancient Bow";
      price = 190.0;
      item = new Bow(name, price, VIP, synergyDamage, count);
      if (item != nullptr) {
        Shop shop;
        shop.buyItemWithCountLimit(choice, human, item, 5);
      }
      break;
    case 23:
      name = "Stealth Ninja Star";
      price = 75.0;
      item = new NinjaStar(name, price, VIP, synergyDamage, count);
      if (item != nullptr) {
        Shop shop;
        shop.buyItemWithCountLimit(choice, human, item, 5);
      }
      break;
    case 24:
      name = "Inferno Fireball";
      price = 205.0;
      item = new FireBall(name, price, VIP, synergyDamage, count);
      if (item != nullptr) {
        Shop shop;
        shop.buyItemWithCountLimit(choice, human, item, 5);
      }
      break;
    case 25:
      name = "Skybreaker Rocket";
      price = 320.0;
      item = new Rocket(name, price, VIP, number, synergyDamage, count);
      if (item != nullptr) {
        Shop shop;
        shop.buyItemWithCountLimit(choice, human, item, 5);
      }
      break;
    case 26:
      name = "Blast Grenade";
      price = 180.0;
      item = new Grenade(name, price, VIP, synergyDamage, count);
      if (item != nullptr) {
        Shop shop;
        shop.buyItemWithCountLimit(choice, human, item, 5);
      }
      break;
    case 27:
      name = "Ensnaring Spider Net";
      price = 50.0;
      item = new SpiderNet(name, price, VIP, synergyDamage, count);
      if (item != nullptr) {
        Shop shop;
        shop.buyItemWithCountLimit(choice, human, item, 5);
      }
      break;
    case 28:
      name = "Warrior's Flipflops";
      price = 30.0;
      item = new Flipflops(name, price, VIP, synergyDamage, count);
      if (item != nullptr) {
        Shop shop;
        shop.buyItemWithCountLimit(choice, human, item, 5);
      }
      break;
    case 29:
      name = "Elixir of Healing";
      price = 100.0;
      item = new HealingPotion(name, price, VIP, 50.0, count);
      if (item != nullptr) {
        Shop shop;
        shop.buyItemWithCountLimit(choice, human, item, 5);
      }
      break;
    case 30:
      name = "Potion of Ravaging";
      price = 110.0;
      item = new DamagePotion(name, price, VIP, 20.0, count);
      if (item != nullptr) {
        Shop shop;
        shop.buyItemWithCountLimit(choice, human, item, 5);
      }
      break;
    case 31:
      name = "Potion of Fortification";
      price = 95.0;
      item = new DefensePotion(name, price, VIP, 20.0, count);
      if (item != nullptr) {
        Shop shop;
        shop.buyItemWithCountLimit(choice, human, item, 5);
      }
      break;
    case 32:
      name = "Brew of Stamina";
      price = 85.0;
      item = new StaminaPotion(name, price, VIP, 20.0, count);
      if (item != nullptr) {
        Shop shop;
        shop.buyItemWithCountLimit(choice, human, item, 5);
      }
      break;
    case 33:
      name = "Feast of Kings";
      price = 45.0;
      item = new Food(name, price, VIP, 10.0, count);
      if (item != nullptr) {
        Shop shop;
        shop.buyItemWithCountLimit(choice, human, item, 5);
      }
      break;
    case 34:
      name = "Sweet Tea of Vigor";
      price = 25.0;
      item = new SweetTea(name, price, VIP, 10.0, count);
      if (item != nullptr) {
        Shop shop;
        shop.buyItemWithCountLimit(choice, human, item, 5);
      }
      break;
    case 35:
      name = "Saffron of Sight";
      price = 220.0;
      item = new Saffron(name, price, VIP, 10.0, count);
      if (item != nullptr) {
        Shop shop;
        shop.buyItemWithCountLimit(choice, human, item, 5);
      }
      break;
    case 36:
      name = "Aragh Nana - Spirit of the Forest";
      price = 65.0;
      item = new AraghNana(name, price, VIP, 10.0, count);
      if (item != nullptr) {
        Shop shop;
        shop.buyItemWithCountLimit(choice, human, item, 5);
      }
      break;
    case 37:
      name = "Nuts of the Ancients";
      price = 55.0;
      item = new Nuts(name, price, VIP, 10.0, count);
      if (item != nullptr) {
        Shop shop;
        shop.buyItemWithCountLimit(choice, human, item, 5);
      }
      break;
    default:
      cout << "Invalid choice." << endl;
  }
  return item;
}