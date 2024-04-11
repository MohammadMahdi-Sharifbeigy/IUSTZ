#include "Shop.h"
#include <fstream>
#include <iostream>
#include <random>
#include <vector>
#include "Login.cpp"
#include "../Items/CheckNumber.h"
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
#include "../Items/ItemFactory.h"

using namespace std;

Shop::Shop() {}

void Shop::showShop() {
  cout << "********************************************************************"
          "********************"
       << endl;
  cout << "*                                      SHOP ITEMS                   "
          "                   *"
       << endl;
  cout << "--------------------------------------------------------------------"
          "--------------------"
       << endl;

  // ARMORS
  cout << "| ARMORS               |   Price   |  Quantity  |         VIP       "
          "   |    BestMach   |"
       << endl;
  cout << "--------------------------------------------------------------------"
          "--------------------"
       << endl;
  cout << "| 1. Armor             |    150    |     2      |         "
          "\033[1;31mNo\033[0m           |    Paladin    |"
       << endl;
  cout << "| 2. Shield            |    120    |     5      |         "
          "\033[1;31mNo\033[0m           |    Assassin   |"
       << endl;
  cout << "| 3. Magic Shield      |    200    |     3      |         "
          "\033[1;31mNo\033[0m           |    Wizard     |"
       << endl;
  cout << "| 4. Iron Body         |    250    |     1      |         "
          "\033[1;31mNo\033[0m           |    Cyborg     |"
       << endl;
  cout << "| 5. Bulletproof Jaket |    180    |     10     |         "
          "\033[1;34mYes\033[0m          |    Sniper     |"
       << endl;
  cout << "| 6. Cloak             |    160    |     4      |         "
          "\033[1;31mNo\033[0m           |    SuperHero  |"
       << endl;
  cout << "| 7. Pesian Dad        |    300    |     7      |         "
          "\033[1;34mYes\033[0m          |    AsianMom   |"
       << endl;
  cout << "--------------------------------------------------------------------"
          "--------------------"
       << endl;

  // WEAPONS
  cout << "| WEAPONS              |   Price   |  Quantity  |         VIP       "
          "   |    BestMach   |"
       << endl;
  cout << "--------------------------------------------------------------------"
          "--------------------"
       << endl;
  cout << "| 8. Sword             |    110    |     6      |         "
          "\033[1;31mNo\033[0m           |    Paladin    |"
       << endl;
  cout << "| 9. Spear             |    115    |     3      |         "
          "\033[1;34mYes\033[0m          |    Assassin   |"
       << endl;
  cout << "| 10. Katana           |    220    |     2      |         "
          "\033[1;31mNo\033[0m           |    Assasson   |"
       << endl;
  cout << "| 11. Poison Dagger    |    130    |     4      |         "
          "\033[1;34mYes\033[0m          |    Wizard     |"
       << endl;
  cout << "| 12. Wand             |    140    |     8      |         "
          "\033[1;31mNo\033[0m           |    Wizard     |"
       << endl;
  cout << "| 13. Book             |    90     |     5      |         "
          "\033[1;34mYes\033[0m          |    Wizard     |"
       << endl;
  cout << "| 14. Laser Gun        |    210    |     2      |         "
          "\033[1;31mNo\033[0m           |    Cyborg     |"
       << endl;
  cout << "| 15. Little Robots    |    310    |     10     |         "
          "\033[1;34mYes\033[0m          |    Cyborg     |"
       << endl;
  cout << "| 16. Snipe            |    250    |     3      |         "
          "\033[1;31mNo\033[0m           |    Sniper     |"
       << endl;
  cout << "| 17. Colt             |    170    |     5      |         "
          "\033[1;31mNo\033[0m           |    SuperHero  |"
       << endl;
  cout << "| 18. Eyelaser         |    280    |     2      |         "
          "\033[1;31mNo\033[0m           |    SuperHero  |"
       << endl;
  cout << "| 19. Whip of Truth    |    150    |     3      |         "
          "\033[1;34mYes\033[0m          |    SuperHero  |"
       << endl;
  cout << "| 20. Swatter          |    60     |     8      |         "
          "\033[1;31mNo\033[0m           |    AsianMom   |"
       << endl;
  cout << "| 21. Pepper           |    40     |     6      |         "
          "\033[1;34mYes\033[0m          |    AsianMom   |"
       << endl;
  cout << "--------------------------------------------------------------------"
          "--------------------"
       << endl;

  // THROWABLE ITEMS
  cout << "| THROWABLE ITEMS      |   Price   |  Quantity  |         VIP       "
          "   |    BestMach   |"
       << endl;
  cout << "--------------------------------------------------------------------"
          "--------------------"
       << endl;
  cout << "| 22. Bow              |    190    |     6      |         ---       "
          "   |    Paladin    |"
       << endl;
  cout << "| 23. Ninja Star       |    75     |     3      |         ---       "
          "   |    Assassin   |"
       << endl;
  cout << "| 24. Fireball         |    205    |     2      |         ---       "
          "   |    Wizard     |"
       << endl;
  cout << "| 25. Rocket           |    320    |     4      |         ---       "
          "   |    Cyborg     |"
       << endl;
  cout << "| 26. Grenade          |    180    |     5      |         ---       "
          "   |    Sniper     |"
       << endl;
  cout << "| 27. Spider Net       |    50     |     1      |         ---       "
          "   |    SuperHero  |"
       << endl;
  cout << "| 28. FlipFlop         |    30     |     3      |         ---       "
          "   |    AsianMom   |"
       << endl;
  cout << "--------------------------------------------------------------------"
          "--------------------"
       << endl;

  // CONSUMABLE ITEMS
  cout << "| CONSUMABLE ITEMS     |   Price   |  Quantity  | Reinforcing "
          "effect on|    BestMach   |"
       << endl;
  cout << "--------------------------------------------------------------------"
          "--------------------"
       << endl;
  cout << "| 29. Healing Potion   |    100    |     10     |          HP       "
          "   |    --------   |"
       << endl;
  cout << "| 30. Damage Potion    |    110    |     8      |        Attack     "
          "   |    --------   |"
       << endl;
  cout << "| 31. Defense Potion   |    95     |     5      |        Defense    "
          "   |    --------   |"
       << endl;
  cout << "| 32. Stamina Potion   |    85     |     7      |        Stamina    "
          "   |    --------   |"
       << endl;
  cout << "| 33. Food             |    45     |     9      |     HP and "
          "Stamina   |    --------   |"
       << endl;
  cout << "| 34. Sweet Tea        |    25     |     3      |          HP       "
          "   |    AsianMom   |"
       << endl;
  cout << "| 35. Saffron          |    220    |     2      |        Attack     "
          "   |    AsianMom   |"
       << endl;
  cout << "| 36. Aragh Nana       |    65     |     4      |        Defense    "
          "   |    AsianMom   |"
       << endl;
  cout << "| 37. Nuts             |    55     |     6      |        Defense    "
          "   |    AsianMom   |"
       << endl;
  cout << "--------------------------------------------------------------------"
          "--------------------"
       << endl;

  cout << "********************************************************************"
          "********************"
       << endl;
}

void Shop::buyItem(Human* human) {
  int choice = 1;
  Shop shop = Shop();

  while (choice != 0) {
    shop.showShop();
    cout << "Coins : " << human->getCoin() << endl;
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
    if (choice == 0) {
      break;
    } else if (choice >= 1 && choice <= 21) {
      buy(choice, human);
    } else {
      Item* item = ItemFactory::createItem(choice, human, true);
      buyItemWithCountLimit(choice, human, item, 5);
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

  if (nowcount >= maxCount) {
    cout << "Sorry, you already have the maximum limit of " << maxCount
         << " of this item. You can't buy more!" << endl;
    return;
  }
    if(item->isVIP()){
        if(human->getLevel()<5){
            cout<<"Sorry you can't buy VIP items untill you reach level 5"<<endl;
            return;
        }
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

   sf::SoundBuffer BuyBuffer;
    if (!BuyBuffer.loadFromFile("GameLoop/Buy.wav")) {
        std::cerr << "Could not load the Buy audio file!" << std::endl;
    }

    // Create a sound object and play it
    sf::Sound BuySound;
    BuySound.setBuffer(BuyBuffer);
    BuySound.play();
    // Wait until the sound is finished
      while (BuySound.getStatus() == sf::Sound::Playing) {
          // Keep the program running until the sound has finished playing
         cout << "you bought " << item->getName() << "!" << endl;
          sf::sleep(sf::milliseconds(2000));

      }
  human->setCoin(human->getCoin() - totalPrice);
  human->addInventory(item, count);
}

void Shop::buy(int choice, Human* human) {
  Item* item = ItemFactory::createItem(choice, human, false);
    if(item->isVIP()){
        if(human->getLevel()<5){
            cout<<"Sorry you can't buy VIP items untill you reach level 5"<<endl;
            return;
        }
    }
  if (human->getCoin() < item->getPrice()) {
    cout << "Sorry, you don't have enough coins to buy the item." << endl;
  } else if (human->existInInventory(item)) {
    cout << "You already have the item!" << endl;
  } else {
    human->setCoin(human->getCoin() - item->getPrice());
     // Load an audio file
    sf::SoundBuffer BuyBuffer;
    if (!BuyBuffer.loadFromFile("GameLoop/Buy.wav")) {
        std::cerr << "Could not load the Buy audio file!" << std::endl;
    }

    // Create a sound object and play it
    sf::Sound BuySound;
    BuySound.setBuffer(BuyBuffer);
    BuySound.play();
    // Wait until the sound is finished
      while (BuySound.getStatus() == sf::Sound::Playing) {
          // Keep the program running until the sound has finished playing
         cout << "you bought " << item->getName() << "!" << endl;
         
          sf::sleep(sf::milliseconds(2000));
      } 
    human->addInventory(item);
  }
}

void Shop::sell(Human* human) {
//  human->showInventory();
  if (human->inventorySize() == 0) {
    cout << "You don't have any items to sell! Enter 0 to exit." << endl;
    int index;
    string sindex;
    try {
      cin >> sindex;
      if (check_number(sindex) == 0 || stoi(sindex) != 0) {
        throw sindex;
      }
    } catch (...) {
      while (check_number(sindex) == 0 || stoi(sindex) != 0) {
        cout << "Invalid choice." << endl
             << "Enter 0 to exit the shop:" << endl;
        cin >> sindex;
      }
    }
    return;
  }
  int index = 1;
  string sindex;
  while (index != 0) {
      human->showInventory();
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
        Item* item = human->itemsAt(index);

              // Load an audio file
      sf::SoundBuffer SellBuffer;
      if (!SellBuffer.loadFromFile("GameLoop/coin.wav")) {
          std::cerr << "Could not load the Sell audio file!" << std::endl;
      }

      // Create a sound object and play it
      sf::Sound SellSound;
      SellSound.setBuffer(SellBuffer);
      SellSound.play();
      // Wait until the sound is finished
      while (SellSound.getStatus() == sf::Sound::Playing) {
          // Keep the program running until the sound has finished playing
         cout << "You sold "<<count<<" "<<item->getName()<<endl;
          sf::sleep(sf::milliseconds(2000));

      }
      human->removeInventory(index, count);
      human->setCoin(human->getCoin() + price * count);
        cout << "Coins : "<< human->getCoin()<<endl;
    } else {
        count = 1;
      double price = human->priceItemsAt(index);
        Item* item = human->itemsAt(index);
                  // Load an audio file
      sf::SoundBuffer SellBuffer;
      if (!SellBuffer.loadFromFile("GameLoop/coin.wav")) {
          std::cerr << "Could not load the Sell audio file!" << std::endl;
      }

      // Create a sound object and play it
      sf::Sound SellSound;
      SellSound.setBuffer(SellBuffer);
      SellSound.play();
      // Wait until the sound is finished
      while (SellSound.getStatus() == sf::Sound::Playing) {
          // Keep the program running until the sound has finished playing
         cout << "You sold "<<count<<" "<<item->getName()<<endl;
          sf::sleep(sf::milliseconds(2000));

      }
      human->removeInventory(index, count);
      human->setCoin(human->getCoin() + price * count);
        cout << "Coins : "<< human->getCoin()<<endl;
    }
  }
}

void Shop::welcomShop(Human* human) {
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
    shop.buyItem(human);
    //  saveCharacter(human);
  } else if (choice == 2) {
    shop.sell(human);
    //  saveCharacter(human);
  }
}