#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <filesystem>
#include <iostream>
#include <limits>
#include <vector>
#include "Character.h"
#include "CharacterType.h"
#include "Enemy.h"
#include "EnemyFactory.h"
#include "GameState.h"
#include "HealingPotion.h"
#include "HumanEnemy.h"
#include "Login.cpp"
#include "Paladin.h"
#include "Shop.h"
#include "Sword.h"
#include "Zombie.h"
#include "font.h"
// #include "Save.h"

#ifdef _WIN32
#include <conio.h>
#include <direct.h>
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

void displayHealthBar(string name, double currentHP, double maxHP);

void clearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void sleepMilliseconds(int milliseconds) {
#ifdef _WIN32
  Sleep(milliseconds);
#else
  usleep(milliseconds * 1000);
#endif
}
void waitForEnter() {
  cout << "Press Enter to continue...";
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  string input;
  getline(cin, input);
}

void playerDied(Human* player) {
  if (player->getCoin() >= 100) {
    cout << "You have " << player->getCoin() << " gold." << endl;
    cout << "Would you like to play again? (y/n)" << endl;
    cout << "It will cost you 50 gold, but your stats will be unchanged."
         << endl;
    cout << "If you choose not to play again, the game will exit, and your "
            "account will be deleted."
         << endl;
    char choice;
    cin >> choice;
    if (choice == 'y') {
      player->setCurrentHP(player->getMaxHP());
      player->setCoin(player->getCoin() - 100);
      clearScreen();
      return;
    } else {
      filesystem::remove(player->getName() + ".csv");
      // remove player name from usernames.csv
      ifstream file("usernames.csv");
      ofstream temp("temp.csv");
      string line;
      while (getline(file, line)) {
        // search in each line for player name
        if (line.find(player->getName()) == string::npos) {
          temp << line << endl;
        }
      }
      file.close();
      temp.close();
      filesystem::remove("usernames.csv");
      filesystem::rename("temp.csv", "usernames.csv");
      exit(0);
    }
  } else {
    cout << "You have no gold." << endl;
    cout << "Would you like to play again? (y/n)" << endl;
    cout << "Your stats will be set to default." << endl;
    cout << "If you choose not to play again, the game will exit, and your "
            "account will be deleted."
         << endl;
    char choice;
    cin >> choice;
    if (choice == 'y') {
      player->setCurrentHP(player->getMaxHP());
      player->setCoin(0);
      player->setCurrXP(0);
      player->setLevel(1);
      clearScreen();
      return;
    } else {
      exit(0);
    }
  }
}

void attackZombie(Human* player, Enemy* zombie) {
  static const char* attackMessages[] = {
      " swings a heavy blow at the Zombie, who reels from the impact!",
      " charges forward, weapon in hand, landing a solid hit on the Zombie!",
      " lashes out quickly, striking the Zombie with precision!",
      " unleashes a furious assault on the Zombie, driving it back!",
      " finds an opening and attacks, dealing a significant blow to the "
      "Zombie!",
      " executes a swift strike, cutting through the air towards the Zombie!"};
  int msgIndex = rand() % (sizeof(attackMessages) / sizeof(attackMessages[0]));
  cout << player->getName() << attackMessages[msgIndex]
       << " The Zombie staggers, left with " << zombie->getCurrentHP()
       << " health." << endl
       << endl;
}

void useHealingPotion(Human* player) {
  static const char* potionMessages[] = {
      " gulps down a potion, feeling a surge of energy!",
      " drinks a healing potion, wounds beginning to close!",
      " consumes the potion, vitality restoring rapidly!",
      " finds a moment's peace to drink a potion, health surging back!",
      " quickly downs a potion, feeling rejuvenated!",
      " uses a healing potion, instantly feeling better!"};
  int msgIndex = rand() % (sizeof(potionMessages) / sizeof(potionMessages[0]));
  cout << player->getName() << potionMessages[msgIndex] << endl;
}

void checkInventory(Human* player) {
  static const char* inventoryMessages[] = {
      " rifles through their pack for something useful...",
      " searches their belongings for any advantage...",
      " digs into their bag, seeking aid in the midst of battle...",
      " hastily looks over their inventory, eyes darting back to the Zombie...",
      " frantically searches through their items, heart racing...",
      " checks their gear, hoping for something to turn the tide..."};
  int msgIndex =
      rand() % (sizeof(inventoryMessages) / sizeof(inventoryMessages[0]));
  cout << player->getName() << inventoryMessages[msgIndex] << endl;
}

void victoryOverZombie(Enemy* zombie) {
  static const char* victoryMessages[] = {
      " collapses into a heap, finally still. Silence returns...",
      " falls apart, defeated at last. You take a moment to catch your breath.",
      " is vanquished. Its terrifying presence fades away as peace settles in.",
      " lies defeated, its reign of terror ended by your hand.",
      " crumples to the ground, no longer a threat. You've won this battle.",
      " is bested, its form collapsing into dust. Victory is yours."};
  int msgIndex =
      rand() % (sizeof(victoryMessages) / sizeof(victoryMessages[0]));
  cout << "\nThe Zombie" << victoryMessages[msgIndex] << endl;
}

void defeatedByZombie(Human* player) {
  static const char* defeatMessages[] = {
      " falls to the ground, the world fading to black. This is the end...",
      " is overwhelmed, vision blurring as darkness takes hold.",
      " can fight no longer, succumbing to the encroaching shadows.",
      " collapses, the Zombie's grim figure the last thing they see.",
      " is defeated, their final breath a whisper in the night.",
      " finds no escape from the relentless assault, and darkness descends."};
  int msgIndex = rand() % (sizeof(defeatMessages) / sizeof(defeatMessages[0]));
  cout << player->getName() << defeatMessages[msgIndex] << endl;
}

void noPotionAvailable(Human* player) {
  static const char* noPotionMessages[] = {
      " scrambles for a potion, only to find none left.",
      " reaches for a healing elixir, but their bag is empty.",
      " desperately seeks a potion, but to no avail.",
      " fumbles through their belongings for a potion, but finds nothing.",
      " searches for a potion, only to remember they've used them all.",
      " looks for a healing potion, realizing too late there are none."};
  int msgIndex =
      rand() % (sizeof(noPotionMessages) / sizeof(noPotionMessages[0]));
  cout << player->getName() << noPotionMessages[msgIndex] << " Panic sets in."
       << endl;
}

const char* exploreEnvironment() {
  static const char* explorationMessages[] = {
      "You tread softly through the dense underbrush, eyes peeled for any sign "
      "of danger or opportunity.",
      "The sound of your steps mingles with the whisper of the wind, as you "
      "make your way through the mysterious terrain.",
      "With cautious optimism, you navigate the unfamiliar landscape, alert to "
      "the secrets it may hold.",
      "The thrill of discovery propels you forward, each step uncovering more "
      "of the world's hidden wonders.",
      "You venture deeper into the wild, driven by the promise of adventure "
      "and the lure of the unknown.",
      "The world around you teems with life and possibility, every corner "
      "offering new paths to explore."};
  int msgIndex =
      rand() % (sizeof(explorationMessages) / sizeof(explorationMessages[0]));
  return explorationMessages[msgIndex];
}

void displayXPBar(Human* player) {
  int barLength = 50;
  double xpRatio =
      static_cast<double>(player->getCurrXP()) / player->getMaxXP();
  int xpUnits = static_cast<int>(barLength * xpRatio);
  const string bar = R"(█)";
  cout << "XP: ";
  cout << "[";
  for (int i = 0; i < xpUnits; ++i) {
    cout << "\033[31;37m" << bar << "\033[30;0m";
  }

  for (int i = 0; i < barLength - xpUnits; ++i) {
    cout << "-";
  }

  cout << "] " << player->getCurrXP() << "/" << player->getMaxXP() << endl;
}

void gainXP(Human* player, Enemy* enemy, int xpGained) {
  static const char* xpMessages[] = {
      " absorbs the fallen foe's essence, gaining ",
      " feels stronger as they acquire ",
      " harvests the spoils of victory, earning ",
      " basks in the glow of triumph, securing ",
      " senses a surge of power, collecting ",
      " revels in their success, receiving "};
  int msgIndex = rand() % (sizeof(xpMessages) / sizeof(xpMessages[0]));

  if (player->getCurrXP() + enemy->get_enemy_exp() >= player->getMaxXP()) {
    cout << player->getName() << xpMessages[msgIndex] << xpGained << " XP."
         << endl;
    player->levelUp();
    cout << "\n"
         << player->getName()
         << " has grown in strength and wisdom, ascending to level "
         << player->getLevel() << "!" << endl;
  } else {
    player->setCurrXP(player->getCurrXP() + enemy->get_enemy_exp());
    cout << player->getName() << xpMessages[msgIndex] << xpGained << " XP."
         << endl;
    displayXPBar(player);
  }
}

void enemyAttack(Enemy* enemy, Human* player) {
  static const char* attackMessages[] = {
      " lunges with a ferocious snarl, claws bared!",
      " strikes with a sudden, ghastly ferocity!",
      " shambles forward, launching into a gruesome attack!",
      " emits a horrifying groan, intensifying its assault!",
      " moves with eerie speed, attacking with undead fury!",
      " unleashes a barrage of bites and scratches, relentless in its "
      "pursuit!"};
  int msgIndex = rand() % (sizeof(attackMessages) / sizeof(attackMessages[0]));
  double damage =
      enemy->getAttack();  // Assuming getAttack() returns the damage value
  player->takeDamage(
      damage);  // Simulate the player taking damage from the zombie

  cout << "The " << enemy->getName() << attackMessages[msgIndex] << " "
       << player->getName() << " suffers " << damage << " damage!" << endl
       << endl;
}

bool containsHealingPotion(const vector<Item*>& items) {
  return any_of(items.begin(), items.end(), [](Item* item) {
    return dynamic_cast<HealingPotion*>(item) != nullptr;
  });
}

void displayMainMenu() {
  cout << "\nMain Menu:\n"
       << "1. Explore\n"
       << "2. Shop\n"
       << "3. View Inventory\n"
       << "4. Quit Game\n"
       << "5. Save Game\n"
       << "Enter your choice: ";
}

void displayPlayerStats(Human* player) {
  cout << "\nPlayer Stats:\n"
       << "HP: " << player->getCurrentHP() << "/" << player->getMaxHP() << "\n"
       << "Attack: " << player->getAttack() << "\n"
       << "Defense: " << player->getDefense() << "\n"
       << "Gold: " << player->getCoin() << "\n"
       << "Level: " << player->getLevel() << "\n"
       << "XP: " << player->getCurrXP() << "/" << player->getMaxXP() << "\n"
       << "Inventory:\n";
  vector<Item*> items = player->getInventory();
  for (size_t i = 0; i < items.size(); ++i) {
    cout << items[i]->getName() << " x" << items[i]->getCount() << "\n";
  }
}

void handleShopInteraction(GameState& gameState) {
  Shop& shop = gameState.getGameShop();
  shop.welcomShop(gameState.getPlayerCharacter());
}

void combatMenu(Human* player) {
  cout << "\nCombat Options:" << endl;
  cout << "1. Attack" << endl;
  cout << "2. Defend" << endl;
  cout << "3. Use Potion" << endl;
  cout << "4. View Inventory" << endl;
  cout << "Choose an action: ";
}

void displayHealthBar(string name, double currentHP, double maxHP) {
  int barLength = 50;
  double healthRatio = currentHP / maxHP;
  int healthUnits = int(barLength * healthRatio);
  const string bar = R"(█)";
  cout << name << " HP: ";
  cout << "[";
  for (int i = 0; i < healthUnits; ++i) {
    cout << "\033[31;40m" << bar << "\033[30;0m";
  }

  for (int i = 0; i < barLength - healthUnits; ++i) {
    cout << "-";
  }

  cout << "] " << int(currentHP) << "/" << maxHP << endl;
}

void combat(Human* player, Enemy* enemy) {
  srand(static_cast<unsigned int>(time(0)));
  //Character* target = nullptr;
  int enemy_max_hp = enemy->getMaxHP();
  cout << "\nA wild " << enemy->getName() << " appears!" << endl;
  displayHealthBar(player->getName(), player->getCurrentHP(),
                   player->getMaxHP());
  cout << endl;
  displayHealthBar(enemy->getName(), enemy->getCurrentHP(), enemy_max_hp);
  while (player->getCurrentHP() > 0 && enemy->getCurrentHP() > 0) {
    vector<Item*> items = player->getInventory();
    vector<Item*> defenseItems;
    double synergy;
    Item* playerPotion;
    combatMenu(player);
    int choice;
    cin >> choice;
    switch (choice) {
      case 1:
        clearScreen();
        // synergy = player->chooseAtkItem();
        enemy->takeDamage(player->getAttack() + (int)synergy);
        // target = dynamic_cast<Enemy*>(enemy);
        // player->setAttack(player->getAttack() + (int)synergy);
        // player->performAttack(*target);
        attackZombie(player, enemy);
        break;
      case 2:
        clearScreen();
        for (size_t i = 0; i < items.size(); ++i) {
          if (items[i]->getID() >= 1 && items[i]->getID() <= 7) {
            defenseItems.push_back(items[i]);
          }
        }
        if (defenseItems.size() == 0) {
          cout << "No defense items available." << endl;
          displayHealthBar(player->getName(), player->getCurrentHP(),
                           player->getMaxHP());
          cout << endl;
          displayHealthBar(enemy->getName(), enemy->getCurrentHP(),
                           enemy_max_hp);
          continue;
        }
        cout << "Choose a defense item to use:" << endl;
        for (size_t i = 0; i < defenseItems.size(); ++i) {
          cout << i + 1 << ". " << defenseItems[i]->getName() << endl;
        }
        int defenseChoice;
        cin >> defenseChoice;
        while (defenseChoice < 1 || defenseChoice > defenseItems.size()) {
          cout << "Invalid choice." << endl;
          cin >> defenseChoice;
        }
        enemy->setAttack(enemy->getAttack() * 0.7);
        cout << player->getName() << " uses "
             << defenseItems[defenseChoice - 1]->getName() << " for defense."
             << endl;
        displayHealthBar(player->getName(), player->getCurrentHP(),
                         player->getMaxHP());
        cout << endl;
        displayHealthBar(enemy->getName(), enemy->getCurrentHP(), enemy_max_hp);
        break;
      case 3:
        clearScreen();
        playerPotion = player->choosePotion();
        if (playerPotion == nullptr) {
          continue;
        } else {
          if (playerPotion->getID() == 29) {
            dynamic_cast<HealingPotion*>(playerPotion)->increaseHP(*player);
            player->removeInventory(player->indexInInventory(playerPotion) + 1);

          } else if (playerPotion->getID() == 30) {
            dynamic_cast<DamagePotion*>(playerPotion)->increaseDamage(*player);
            player->removeInventory(player->indexInInventory(playerPotion) + 1);

          } else if (playerPotion->getID() == 31) {
            dynamic_cast<DefensePotion*>(playerPotion)
                ->increaseDefense(*player);
            player->removeInventory(player->indexInInventory(playerPotion) + 1);

          } else if (playerPotion->getID() == 32) {
            dynamic_cast<StaminaPotion*>(playerPotion)
                ->increaseStamina(*player);
            player->removeInventory(player->indexInInventory(playerPotion) + 1);

          } else if (playerPotion->getID() == 33) {
            dynamic_cast<Food*>(playerPotion)->increaseStats(*player);
            player->removeInventory(player->indexInInventory(playerPotion) + 1);

          } else if (playerPotion->getID() == 34) {
            dynamic_cast<SweetTea*>(playerPotion)->increaseHP(*player);
            player->removeInventory(player->indexInInventory(playerPotion) + 1);

          } else if (playerPotion->getID() == 35) {
            dynamic_cast<Saffron*>(playerPotion)->increaseDamage(*player);
            player->removeInventory(player->indexInInventory(playerPotion) + 1);

          } else if (playerPotion->getID() == 36) {
            dynamic_cast<AraghNana*>(playerPotion)->increaseDefense(*player);
            player->removeInventory(player->indexInInventory(playerPotion) + 1);

          } else if (playerPotion->getID() == 37) {
            dynamic_cast<Nuts*>(playerPotion)->increaseStamina(*player);
            player->removeInventory(player->indexInInventory(playerPotion) + 1);
          }

          break;
        }
      case 4:
        clearScreen();
        checkInventory(player);
        player->showInventory();
        continue;  // Skip enemy's turn
    }

    if (enemy->getCurrentHP() <= 0) {
      victoryOverZombie(enemy);
      gainXP(player, enemy, enemy->get_enemy_exp());
      cout << endl << "\033[38;2;45;220;45m" << well2 << "\033[0m";
      double avgGold = 150;
      if (enemy->getRole() == characterType::WEAKZOMBIE) {
        player->setCoin(player->getCoin() + 0.4 * avgGold);
        cout << "You gained " << 0.4 * avgGold << " gold." << endl;
      } else if (enemy->getRole() == characterType::STRONGZOMBIE) {
        player->setCoin(player->getCoin() + 0.7 * avgGold);
        cout << "You gained " << 0.7 * avgGold << " gold." << endl;
      } else if (enemy->getRole() == characterType::HUMANENEMY) {
        player->setCoin(player->getCoin() + 1.2 * avgGold);
        cout << "You gained " << 1.2 * avgGold << " gold." << endl;
      } else {
        player->setCoin(player->getCoin() + 0.2 * avgGold);
        cout << "You gained " << 0.2 * avgGold << " gold." << endl;
      }
      waitForEnter();
      clearScreen();
      break;
    }

    // Enemy's turn to attack
    if (enemy->getRole() != characterType::WEAKZOMBIE ||
        enemy->getRole() != characterType::STRONGZOMBIE) {
      dynamic_cast<HumanEnemyModel*>(enemy)->Update(*player);
    } else {
      player->takeDamage(enemy->get_enemy_atk());
      enemyAttack(enemy, player);
    }

    if (choice == 2) {
      enemy->setAttack(enemy->getAttack() / 0.7);
    }
    if (player->getCurrentHP() <= 0) {
      defeatedByZombie(player);
      cout << endl << "\033[38;5;52m" << You_Died << "\033[38;5;232m";
      waitForEnter();
      clearScreen();
      playerDied(player);
      return;
    }
    displayHealthBar(player->getName(), player->getCurrentHP(),
                     player->getMaxHP());
    cout << endl;
    displayHealthBar(enemy->getName(), enemy->getCurrentHP(), enemy_max_hp);
  }
}

void explore(GameState& gameState) {
  srand(time(nullptr));    // Seed for random number generation
  int event = rand() % 4;  // Random event: 0, 1, 2 or 3

  Human* player = gameState.getPlayerCharacter();
  characterType types[3] = {characterType::WEAKZOMBIE,
                            characterType::STRONGZOMBIE,
                            characterType::HUMANENEMY};
  characterType type = types[rand() % 3];
  Enemy* enemy = EnemyFactory::createEnemy(type, player->getLevel(), player, nullptr);
  Item* potion = new HealingPotion("Elixir of Healing", 50.0, false, 50.0, 1);
  switch (event) {
    case 0:
      cout << exploreEnvironment() << endl;
      sleepMilliseconds(3000);
      cout << "You found a healing potion on the ground." << endl;
      player->addInventory(potion);
      saveCharacter(player);
      break;
    case 1:
      cout << exploreEnvironment() << endl;
      sleepMilliseconds(3000);
      cout << "You encountered a trap! You lose 10 HP." << endl;
      player->takeDamage(10);
      displayHealthBar(player->getName(), player->getCurrentHP(),
                       player->getMaxHP());
      if (player->getCurrentHP() <= 0) {
        cout << endl << "\033[38;5;52m" << You_Died << "\033[38;5;232m";
        waitForEnter();
        clearScreen();
        playerDied(player);
      }
      saveCharacter(player);
      break;
    case 2:
      cout << exploreEnvironment() << endl;
      sleepMilliseconds(3000);
      cout << "You found a hidden treasure chest containing 50 gold!" << endl;
      player->setCoin(player->getCoin() + 50);
      saveCharacter(player);
      break;
    case 3:
      cout << exploreEnvironment() << endl;
      sleepMilliseconds(3000);
      cout << "You encountered a " << enemy->getName() << "!" << endl;
      sleepMilliseconds(1000);
      cout << "One! ";
      sleepMilliseconds(1000);
      cout << "Two! ";
      sleepMilliseconds(1000);
      cout << "...And Three!";
      sleepMilliseconds(1500);
      clearScreen();
      combat(gameState.getPlayerCharacter(), enemy);
      clearScreen();
      saveCharacter(player);
      break;
    default:
      cout << "It's a peaceful walk. Nothing happens." << endl;
  }
}

void gameLoop(GameState& gameState) {
  bool exitGame = false;

  while (!exitGame && !gameState.isGameOver()) {
    displayMainMenu();
    int choice;
    cin >> choice;

    switch (choice) {
      case 1:
        explore(gameState);
        break;
      case 2:
        handleShopInteraction(gameState);
        break;
      case 3:
        displayPlayerStats(gameState.getPlayerCharacter());
        break;
      case 4:
        exitGame = true;
        break;
      case 5:
        saveCharacter(gameState.getPlayerCharacter());
        break;
      default:
        cout << "Invalid choice, please try again.\n";
    }
  }
}

int main() {
  clearScreen();
  Human* playerCharacter = Login();
  GameState gameState(playerCharacter);
  gameLoop(gameState);
  return 0;
}
