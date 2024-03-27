#include "Shop.h"
#include <fstream>
#include <iostream>
#include <random>
#include <vector>
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
#include "ItemFactory.h"
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

using namespace std;

Shop::Shop() {}

void Shop::showShop() {
  cout << "********SHOP ITEMS********" << endl << endl << endl;
  cout << "ARMORS:" << endl << endl;
  cout << "1.Armor" << endl
       << "Price:" << endl
       << "Best Match : Paladin" << endl
       << "Is VIP : No" << endl
       << endl;
  cout << "2.Shield" << endl
       << "Price:" << endl
       << "Best Match : Assasin" << endl
       << "Is VIP : No" << endl
       << endl;
  cout << "3.Magic Shield" << endl
       << "Price:" << endl
       << "Best Match : Wizard" << endl
       << "Is VIP : No" << endl
       << endl;
  cout << "4.Iron Body" << endl
       << "Price:" << endl
       << "Best Match : Cyborg" << endl
       << "Is VIP : No" << endl
       << endl;
  cout << "5.Bulletproof Jaket" << endl
       << "Price:" << endl
       << "Best Match : Sniper" << endl
       << "Is VIP : Yes" << endl
       << endl;
  cout << "6.Cloak" << endl
       << "Price:" << endl
       << "Best Match : SuperHero" << endl
       << "Is VIP : No" << endl
       << endl;
  cout << "7.Asian Dad" << endl
       << "Price:" << endl
       << "Best Match : Asian Mom" << endl
       << "Is VIP : Yes" << endl
       << endl
       << endl;
  cout << "WEAPONS:" << endl << endl;
  cout << "8.Sward" << endl
       << "Price:" << endl
       << "Best Match : Paladin" << endl
       << "Is VIP : No" << endl
       << endl;
  cout << "9.Spear" << endl
       << "Price:" << endl
       << "Best Match : Paladin" << endl
       << "Is VIP : Yes" << endl
       << endl;
  cout << "10.Katana" << endl
       << "Price:" << endl
       << "Best Match : Assasin" << endl
       << "Is VIP : No" << endl
       << endl;
  cout << "11.Poison Dagger" << endl
       << "Price:" << endl
       << "Best Match : Assasin" << endl
       << "Is VIP : Yes" << endl
       << endl;
  cout << "12.Wand " << endl
       << "Price:" << endl
       << "Best Match : Wizard" << endl
       << "Is VIP : No" << endl
       << endl;
  cout << "13.Book" << endl
       << "Price:" << endl
       << "Best Match : Wizard" << endl
       << "Is VIP : Yes" << endl
       << endl;
  cout << "14.Laser Gun" << endl
       << "Price:" << endl
       << "Best Match : Cyborg" << endl
       << "Is VIP : No" << endl
       << endl
       << endl;
  cout << "15.Little Robots" << endl
       << "Price:" << endl
       << "Best Match : Cyborg" << endl
       << "Is VIP : Yes" << endl
       << endl;
  cout << "16.Snipe" << endl
       << "Price:" << endl
       << "Best Match : Sniper" << endl
       << "Is VIP : No" << endl
       << endl;
  cout << "17.Colt" << endl
       << "Price:" << endl
       << "Best Match : Sniper" << endl
       << "Is VIP : No" << endl
       << endl;
  cout << "18.Eyelaser" << endl
       << "Price:" << endl
       << "Best Match : SuperHero" << endl
       << "Is VIP : No" << endl
       << endl;
  cout << "19.Whip of Truth " << endl
       << "Price:" << endl
       << "Best Match : SuperHero" << endl
       << "Is VIP : Yes" << endl
       << endl;
  cout << "20.Swatter" << endl
       << "Price:" << endl
       << "Best Match : Asian Mom" << endl
       << "Is VIP : No" << endl
       << endl;
  cout << "21.Pepper" << endl
       << "Price:" << endl
       << "Best Match : Asian Mom" << endl
       << "Is VIP : Yes" << endl
       << endl
       << endl;
  cout << "THROWABLE ITEMS:" << endl << endl;
  cout << "22.Bow" << endl
       << "Price:" << endl
       << "Best Match : Paladin" << endl
       << endl;
  cout << "23.Ninja Star" << endl
       << "Price:" << endl
       << "Best Match : Assasin" << endl
       << endl;
  cout << "24.Fireball" << endl
       << "Price:" << endl
       << "Best Match : Wizard" << endl
       << endl;
  cout << "25.Rocket" << endl
       << "Price:" << endl
       << "Best Match : Cyborg" << endl
       << endl;
  cout << "26.Grenade" << endl
       << "Price:" << endl
       << "Best Match : Sniper" << endl
       << endl;
  cout << "27.Spider Net" << endl
       << "Price:" << endl
       << "Best Match : SuperHero" << endl
       << endl;
  cout << "28.FlipFlop" << endl
       << "Price:" << endl
       << "Best Match : Asian Mom" << endl
       << endl
       << endl;
  cout << "COUNSUMEABLE ITEMS:" << endl << endl;
  cout << "29.Healing Potion" << endl
       << "Price:" << endl
       << "Reinforcing effect on : HP" << endl
       << endl;
  cout << "30.Damage Potion" << endl
       << "Price:" << endl
       << "Reinforcing effect on : Attack" << endl
       << endl;
  cout << "31.Defense Poition" << endl
       << "Price:" << endl
       << "Reinforcing effect on : Defense" << endl
       << endl;
  cout << "32.Stamin Potion" << endl
       << "Price:" << endl
       << "Reinforcing effect on : Stamin" << endl
       << endl;
  cout << "33.Food" << endl
       << "Price:" << endl
       << "Reinforcing effect on : HP and Stamin" << endl
       << endl;
  cout << "34.Sweet Tea" << endl
       << "Price:" << endl
       << "Reinforcing effect on : HP" << endl
       << "Best Match : Asian Mom" << endl
       << endl;
  cout << "35.Saffron" << endl
       << "Price:" << endl
       << "Reinforcing effect on : Attack" << endl
       << "Best Match : Asian Mom" << endl
       << endl;
  cout << "36.Aragh Nana" << endl
       << "Price:" << endl
       << "Reinforcing effect on : Defense" << endl
       << "Best Match : Asian Mom" << endl
       << endl;
  cout << "37.Nuts" << endl
       << "Price:" << endl
       << "Reinforcing effect on :  Stamin" << endl
       << "Best Match : Asian Mom" << endl
       << endl;
}

void Shop::buyItem(Human* human) {
  int choice = 1;
  Shop shop = Shop();

  while (choice != 0) {
    shop.showShop();
    cout << "Enter the number of the Item you want to buy or enter 0 to exit:"
         << endl;
    string schoice;

    try {
      cin >> schoice;
      if (check_number(schoice) == 0 || stoi(schoice) < 0 ||
          stoi(schoice) > 37) {
        throw schoice;
      }
    } catch (...) {
      while (check_number(schoice) == 0 || stoi(schoice) < 0 ||
             stoi(schoice) > 37) {
        cout << "Invalid choice." << endl
             << "Enter the number of the Item you want to buy or enter 0 to "
                "exit:"
             << endl;
        cin >> schoice;
      }
    }

    choice = stoi(schoice);

    if (choice >= 1 && choice < 37) {
      buy(choice, human);
      // } else if (choice >= 22 && choice < 37) {
      // pass
    } else {
      cout << "Invalid choice. Please try again." << endl;
    }
  }
}

void Shop::buyItemWithCountLimit(int choice,
                                 Human* human,
                                 Item* item,
                                 int maxCount) {
  int count = 0;
  string scount;
  int nowcount = human->countInInventory(item);

  if (nowcount == maxCount) {
    cout << "Sorry, you already have the maximum limit of " << maxCount
         << " of this item. You can't buy more!" << endl;
    return;
  }

  cout << "How many do you want? ";

  try {
    cin >> scount;
    if (check_number(scount) == 0 || stoi(scount) < 1) {
      throw scount;
    }
  } catch (...) {
    while (check_number(scount) == 0 || stoi(scount) < 1) {
      cout << "Invalid input. Please enter a positive number." << endl;
      cin >> scount;
    }
  }

  count = stoi(scount);

  while (count + nowcount > maxCount) {
    cout << "Sorry, you can't have more than " << maxCount << " of this item!"
         << endl;
    cout << "How many do you want? ";
    try {
      cin >> scount;
      if (check_number(scount) == 0 || stoi(scount) < 1) {
        throw scount;
      }
    } catch (...) {
      while (check_number(scount) == 0 || stoi(scount) < 1) {
        cout << "Invalid input. Please enter a positive number." << endl;
        cin >> scount;
      }
    }

    count = stoi(scount);
  }

  int totalPrice = item->getPrice() * count;
  if (human->getCoin() < totalPrice) {
    cout << "Sorry, you don't have enough coins to buy the item." << endl;
    return;
  }

  human->setCoin(human->getCoin() - totalPrice);
  human->addInventory(item, count);
}

void Shop::buy(int choice, Human* human) {
  Item* item = ItemFactory::createItem(choice, human);
  if (human->getCoin() < item->getPrice()) {
    cout << "Sorry, you don't have enough coins to buy the item." << endl;
  } else if (human->existInInventory(item)) {
    cout << "You already have the item!" << endl;
  } else {
    human->setCoin(human->getCoin() - item->getPrice());
    cout << "you bought " << item->getName() << "!" << endl;
    human->addInventory(item);
  }
}

void Shop::sell(Human* human) {
  human->showInventory();
  int index = 1;
  string sindex;
  while (index != 0) {
    cout << "Enter the number of the item that you want to sell or enter 0 to "
            "exit:"
         << endl;
    try {
      cin >> sindex;
      if (check_number(sindex) == 0 || stoi(sindex) < 0 ||
          stoi(sindex) > human->inventorySize()) {
        throw sindex;
      }
    } catch (...) {
      while (check_number(sindex) == 0 || stoi(sindex) < 0 ||
             stoi(sindex) > human->inventorySize()) {
        cout << "Invalid choice." << endl
             << "Enter the number of the Item you want to sell or enter 0 to "
                "exit:"
             << endl;
        cin >> sindex;
      }
    }
    index = stoi(sindex);
    if (index == 0) {
      break;
    }
    int nowcount = human->countItemsAt(index);
    int count = 0;
    string scount;
    if (nowcount > 1) {
      cout << "How many do you want to sell?" << endl;
      try {
        cin >> scount;
        if (check_number(scount) == 0 || stoi(scount) < 1 ||
            stoi(scount) > nowcount) {
          throw scount;
        }
      } catch (...) {
        while (check_number(scount) == 0 || stoi(scount) < 1 ||
               stoi(scount) > nowcount) {
          if (check_number(scount) == 0 || stoi(scount) < 1) {
            cout << "Invalid input." << endl;
          } else {
            cout << "You don't have enough of this item to sell this many!"
                 << endl;
          }
          cin >> scount;
        }
      }
      count = stoi(scount);
      double price = human->priceItemsAt(index);
      human->removeInventory(index, count);
      human->setCoin(human->getCoin() + price * count);
    } else {
      double price = human->priceItemsAt(index);
      human->removeInventory(index);
      human->setCoin(human->getCoin() + price);
    }
  }
}

void Shop::welcom(Human* human) {
  cout << "**********WELCOME TO THE SHOP**********" << endl << endl;
  int choice = 1;
  string schoice;
  cout << "What do you want to do?" << endl
       << "1.Buy Items" << endl
       << "2.Sell Items" << endl
       << "Enter the number of your choice or 0 to exit the shop:" << endl;
  try {
    cin >> schoice;
    if (check_number(schoice) == 0 || stoi(schoice) < 0 || stoi(schoice) > 2) {
      throw schoice;
    }
  } catch (...) {
    while (check_number(schoice) == 0 || stoi(schoice) < 0 ||
           stoi(schoice) > 37) {
      cout << "Invalid choice." << endl
           << "Enter 1 to buy items , 2 to sell items or 0 to exit the shop:"
           << endl;
      cin >> schoice;
    }
  }
  choice = stoi(schoice);
  Shop shop = Shop();
  if (choice == 1) {
    shop.buy(choice, human);
  } else if (choice == 2) {
    shop.sell(human);
  }
}