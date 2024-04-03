#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <vector>
#include "Character.h"
#include "CharacterType.h"
#include "Enemy.h"
#include "GameState.h"
#include "HealingPotion.h"
#include "Login.cpp"
#include "Paladin.h"
#include "Shop.h"
#include "Sword.h"
#include "Zombie.h"
#include "font.h"

#ifdef _WIN32
#include <conio.h>
#include <direct.h>
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

void displayHealthBar(string name, int currentHP, int maxHP);

void clearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void waitForEnter() {
  cout << "Press Enter to continue...";
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  string input;
  getline(cin, input);
}

void sleepMilliseconds(int milliseconds) {
#ifdef _WIN32
  Sleep(milliseconds);
#else
  usleep(milliseconds * 1000);
#endif
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

void zombieAttack(Enemy* zombie, Human* player) {
  static const char* attackMessages[] = {
      " lunges with a ferocious snarl, claws bared!",
      " strikes with a sudden, ghastly ferocity!",
      " shambles forward, launching into a gruesome attack!",
      " emits a horrifying groan, intensifying its assault!",
      " moves with eerie speed, attacking with undead fury!",
      " unleashes a barrage of bites and scratches, relentless in its "
      "pursuit!"};
  int msgIndex = rand() % (sizeof(attackMessages) / sizeof(attackMessages[0]));
  int damage =
      zombie->getAttack();  // Assuming getAttack() returns the damage value
  player->takeDamage(
      damage);  // Simulate the player taking damage from the zombie

  cout << "The Zombie" << attackMessages[msgIndex] << " " << player->getName()
       << " suffers " << damage << " damage!" << endl
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
  cout << "\n--- Shop ---\n";
  shop.welcomShop(gameState.getPlayerCharacter());
}

void combatMenu(Human* player) {
  cout << "\nCombat Options:" << endl;
  cout << "1. Attack" << endl;
  cout << "2. Use Potion" << endl;
  cout << "3. View Inventory" << endl;
  cout << "Choose an action: ";
}

void displayHealthBar(string name, int currentHP, int maxHP) {
  int barLength = 50;
  double healthRatio = static_cast<double>(currentHP) / maxHP;
  int healthUnits = static_cast<int>(barLength * healthRatio);
  const string bar = R"(█)";
  cout << name << " HP: ";
  cout << "[";
  for (int i = 0; i < healthUnits; ++i) {
    cout << "\033[31;40m" << bar << "\033[30;0m";
  }

  for (int i = 0; i < barLength - healthUnits; ++i) {
    cout << "-";
  }

  cout << "] " << currentHP << "/" << maxHP << endl;
}

void combat(Human* player, Enemy* enemy) {
  srand(static_cast<unsigned int>(time(0)));

  int enemy_max_hp = enemy->getMaxHP();
  cout << "\nA wild " << enemy->getName() << " appears!" << endl;
  displayHealthBar(player->getName(), player->getCurrentHP(),
                   player->getMaxHP());
  cout << endl;
  displayHealthBar(enemy->getName(), enemy->getCurrentHP(), enemy_max_hp);
  while (player->getCurrentHP() > 0 && enemy->getCurrentHP() > 0) {
    combatMenu(player);
    int choice;
    cin >> choice;
    switch (choice) {
      case 1:
        clearScreen();
        enemy->takeDamage(player->getAttack());
        attackZombie(player, enemy);
        break;
      case 2:
        clearScreen();
        if (containsHealingPotion(player->getInventory())) {
          vector<Item*> items = player->getInventory();
          for (size_t i = 0; i < items.size(); ++i) {
            HealingPotion* potion = dynamic_cast<HealingPotion*>(items[i]);
            if (potion != nullptr) {
              potion->increaseHP(*player);
              if (items[i]->getCount() - 1 == 0) {
                items.erase(items.begin() + i);
              } else {
                items[i]->setCount(items[i]->getCount() - 1);
              }
              break;
            }
          }
          useHealingPotion(player);
        } else {
          noPotionAvailable(player);
        }
        break;
      case 3:
        clearScreen();
        checkInventory(player);
        player->showInventory();
        continue;  // Skip enemy's turn
    }

    if (enemy->getCurrentHP() <= 0) {
      victoryOverZombie(enemy);
      gainXP(player, enemy, enemy->get_enemy_exp());
      cout << endl << "\033[38;2;45;220;45m" << well2 << "\033[0m";
      waitForEnter();
      clearScreen();
      break;
    }

    // Enemy's turn to attack
    player->takeDamage(enemy->get_enemy_atk());
    zombieAttack(enemy, player);
    if (player->getCurrentHP() <= 0) {
      defeatedByZombie(player);
      cout << endl << "\033[38;5;52m" << You_Died << "\033[38;5;232m";
      waitForEnter();
      clearScreen();
      exit(0);
    }
    displayHealthBar(player->getName(), player->getCurrentHP(),
                     player->getMaxHP());
    cout << endl;
    displayHealthBar(enemy->getName(), enemy->getCurrentHP(), enemy_max_hp);
  }
}

void explore(GameState& gameState) {
  srand(time(nullptr));    // Seed for random number generation
  int event = rand() % 4;  // Random event: 0, 1, or 2

  Human* player = gameState.getPlayerCharacter();
  Enemy zombie(player->getLevel());
  zombie.setName("Zombie");
  zombie.setCurrentHP(zombie.getMaxHP());
  Item* potion = new HealingPotion("Healing Potion", 50.0, false, 50.0, 1);
  switch (event) {
    case 0:
      cout << exploreEnvironment() << endl;
      sleepMilliseconds(3000);
      cout << "You found a healing potion on the ground." << endl;
      player->addInventory(potion);
      break;
    case 1:
      cout << exploreEnvironment() << endl;
      sleepMilliseconds(3000);
      cout << "You encountered a trap! You lose 10 HP." << endl;
      player->takeDamage(10);
      break;
    case 2:
      cout << exploreEnvironment() << endl;
      sleepMilliseconds(3000);
      cout << "You found a hidden treasure chest containing 50 gold!" << endl;
      player->setCoin(player->getCoin() + 50);
      break;
    case 3:
      cout << exploreEnvironment() << endl;
      sleepMilliseconds(3000);
      cout << "You encountered a Zombie!" << endl;
      sleepMilliseconds(1000);
      cout << "One! ";
      sleepMilliseconds(1000);
      cout << "Two! ";
      sleepMilliseconds(1000);
      cout << "...And Three!";
      sleepMilliseconds(1500);
      clearScreen();
      combat(gameState.getPlayerCharacter(), &zombie);
      clearScreen();
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
