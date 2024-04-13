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
#include "GameStateMulti.h"
#include "HealingPotion.h"
#include "HumanEnemy.h"
#include "Login.cpp"
#include "Paladin.h"
#include "Shop.h"
#include "Sword.h"
#include "Zombie.h"
#include "font.h"
#include "ftxui/component/captured_mouse.hpp"  // for ftxui
#include "ftxui/component/component.hpp"  // for Radiobox, Renderer, Tab, Toggle, Vertical
#include "ftxui/component/component_base.hpp"      // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/dom/elements.hpp"  // for Element, separator, operator|, vbox, border
#include "ftxui/component/component_options.hpp"   // for MenuOption
#include "ftxui/dom/elements.hpp"  // for operator|, separator, Element, Decorator, color, text, hbox, size, bold, frame, inverted, vbox, HEIGHT, LESS_THAN, border
#include "ftxui/screen/color.hpp"  // for Color, Color::Blue, Color::Cyan, Color::Green, Color::Red, Color::Yellow

#ifdef _WIN32
#include <conio.h>
#include <direct.h>
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;
using namespace ftxui;

void displayHealthBar(string name, double currentHP, double maxHP);

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
  cout << "The " << enemy->getName() << attackMessages[msgIndex] << endl;
}

bool containsHealingPotion(const vector<Item*>& items) {
  return any_of(items.begin(), items.end(), [](Item* item) {
    return dynamic_cast<HealingPotion*>(item) != nullptr;
  });
}

void displayMainMenu() {
  cout << "Main Menu:\n"
       << "1. Explore\n"
       << "2. Shop\n"
       << "3. View Inventory\n"
       << "4. Quit Game\n"
       << "5. Save Game\n"
       << "Enter your choice: ";
}

string statToString(const string& name, int current, int maximum = -1) {
  if (maximum >= 0) {
    return name + ": " + to_string(current) + "/" + to_string(maximum);
  }
  return name + ": " + to_string(current);
}

// Function to dynamically generate the player's stats for rendering
Element GenerateStats(Human* player) {
  vector<Element> elements;
  elements.push_back(text("Player Stats:") | bold | border);
  elements.push_back(
      text(statToString("HP", player->getCurrentHP(), player->getMaxHP())));
  elements.push_back(text(statToString("Attack", player->getAttack())));
  elements.push_back(text(statToString("Defense", player->getDefense())));
  elements.push_back(text(statToString("Gold", player->getCoin())));
  elements.push_back(text(statToString("Level", player->getLevel())));
  elements.push_back(
      text(statToString("XP", player->getCurrXP(), player->getMaxXP())));

  elements.push_back(separator());
  elements.push_back(text("Inventory:") | bold);
  for (Item* item : player->getInventory()) {
    elements.push_back(
        text(item->getName() + " x" + to_string(item->getCount())));
  }

  return vbox(move(elements)) | border;
}

Component displayPlayerStats(Human* player, function<void()> on_back) {
  return Container::Vertical(
      {Renderer([player] { return GenerateStats(player); }),
       Button("Back", on_back)});
}

void showPlayerStats(ScreenInteractive& screen, Human* player) {
  auto stats_component =
      displayPlayerStats(player, [&] { screen.ExitLoopClosure()(); });
  screen.Loop(stats_component);
}

Component displayGameSaved(function<void()> on_back) {
  return Container::Vertical(
      {Renderer(
           [] { return vbox({text("Game Saved!") | bold | center}) | border; }),
       Button("Back", on_back)});
}

void showGameSavedMessage(ScreenInteractive& screen) {
  auto saved_component = displayGameSaved([&] {
    screen.ExitLoopClosure()();  // Close the "Game Saved" screen and return to
                                 // the main UI
  });
  screen.Loop(saved_component);
}

void handleShopInteraction(GameState& gameState) {
  clearScreen();
  Shop& shop = gameState.getGameShop();
  shop.welcomeShop(gameState.getPlayerCharacter());
}

void easterEgg(Human* player) {
  clearScreen();
  cout << "." << flush;
  sleepMilliseconds(500);
  cout << "." << flush;
  sleepMilliseconds(500);
  cout << "." << flush;
  sleepMilliseconds(500);
  clearScreen();
  cout << "Sike! It's not an option!" << flush << endl;
  sleepMilliseconds(1000);
  cout << "Type \"save\" to get back to the game" << endl;
  string input;
  cin >> input;
  while (input != "save") {
    cout << "I said, type \"save\"" << endl;
    cin >> input;
  }
  clearScreen();
  cout << "." << flush;
  sleepMilliseconds(500);
  cout << "." << flush;
  sleepMilliseconds(500);
  cout << "." << flush;
  sleepMilliseconds(500);
  cout << "Do you want us to save you as PDF or JPEG?" << flush << endl;
  sleepMilliseconds(3000);
  cout << "HAHAHA" << endl;
  sleepMilliseconds(1000);
  cout << "Kidding!" << endl;
  waitForEnter();
  playerDied(player);
}

void combatMenu(Human* player) {
  cout << "\nCombat Options:" << endl;
  cout << "1. Attack" << endl;
  cout << "2. Defend" << endl;
  cout << "3. Use Potion" << endl;
  cout << "4. View Inventory" << endl;
  cout << "0 for Suicide..." << endl;
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
  sleepMilliseconds(500);
  clearScreen();
  srand(static_cast<unsigned int>(time(0)));
  int enemy_max_hp = enemy->getMaxHP();
  displayHealthBar(player->getName(), player->getCurrentHP(),
                   player->getMaxHP());
  cout << endl;
  displayHealthBar(enemy->getName(), enemy->getCurrentHP(), enemy_max_hp);
  while (player->getCurrentHP() > 0 && enemy->getCurrentHP() > 0) {
    vector<Item*> items = player->getInventory();
    vector<Item*> defenseItems;
    double synergy;
    Item* playerPotion;
    Enemy* target;
    Character* chrtarget = nullptr;
    combatMenu(player);
    int choice;
    cin >> choice;
    switch (choice) {
      case 0:
        easterEgg(player);
        break;
      case 1:
        clearScreen();
        synergy = player->chooseAtkItem();
        // enemy->takeDamage(player->getAttack() + (int)synergy);
        chrtarget = dynamic_cast<Enemy*>(enemy);
        player->setAttack(player->getAttack() + (int)synergy);
        player->performAttack(*chrtarget);
        attackZombie(player, enemy);
        player->setAttack(player->getAttack() - (int)synergy);
        break;
      case 2:
        clearScreen();
        chrtarget = dynamic_cast<Enemy*>(enemy);
        synergy = player->chooseDefItems();
        player->setDefense(player->getDefense() + synergy);
        clearScreen();
        player->performDefense(*chrtarget);
        break;
      case 3:
        clearScreen();
        playerPotion = player->choosePotion();
        clearScreen();
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
        waitForEnter();
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
    if (enemy->getRole() != characterType::WEAKZOMBIE &&
        enemy->getRole() != characterType::STRONGZOMBIE) {
      dynamic_cast<HumanEnemyModel*>(enemy)->Update(*player);
    } else {
      player->takeDamage(enemy->get_enemy_atk());
      enemyAttack(enemy, player);
    }

    if (choice == 2) {
      player->setDefense(player->getDefense() - synergy);
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

void combatMulti(Human* player1, Human* player2) {
  srand(static_cast<unsigned int>(time(nullptr)));
  cout << "\n*** Combat Begins ***\n" << endl;
  displayHealthBar(player1->getName(), player1->getCurrentHP(),
                   player1->getMaxHP());
  cout << endl;
  displayHealthBar(player2->getName(), player2->getCurrentHP(),
                   player2->getMaxHP());

  vector<Item*> items1 = player1->getInventory();
  vector<Item*> defenseItems1;
  double synergy1, synergy2, defsynergy1, defsynergy2;
  Item* playerPotion1;

  int choice1;
  vector<Item*> items2 = player2->getInventory();
  vector<Item*> defenseItems2;
  Item* playerPotion2;
  int choice2;

  while (player1->getCurrentHP() > 0 && player2->getCurrentHP() > 0) {
    // Player 1's turn
    cout << endl << player1->getName() << "'s Turn: " << endl;
    combatMenu(player1);
    cin >> choice1;
    switch (choice1) {
      case 0:
        easterEgg(player1);
        break;
      case 1: {
        clearScreen();
        synergy1 = player1->chooseAtkItem();
        player1->setAttack(player1->getAttack() + (int)synergy1);
        player1->performAttack(*player2);
        // player2->takeDamage(player1->getAttack() + (int)synergy1);
        player1->setAttack(player1->getAttack() - (int)synergy1);
        break;
      }
      case 2: {
        clearScreen();
        defsynergy1 = player1->chooseDefItems();
        player1->setDefense(player1->getDefense() + defsynergy1);
        player1->performDefense(*player2);
        break;
      }
      case 3: {
        clearScreen();
        playerPotion1 = player1->choosePotion();
        if (playerPotion1 == nullptr) {
          continue;
        } else {
          if (playerPotion1->getID() == 29) {
            dynamic_cast<HealingPotion*>(playerPotion1)->increaseHP(*player1);
            player1->removeInventory(player1->indexInInventory(playerPotion1) +
                                     1);

          } else if (playerPotion1->getID() == 30) {
            dynamic_cast<DamagePotion*>(playerPotion1)
                ->increaseDamage(*player1);
            player1->removeInventory(player1->indexInInventory(playerPotion1) +
                                     1);

          } else if (playerPotion1->getID() == 31) {
            dynamic_cast<DefensePotion*>(playerPotion1)
                ->increaseDefense(*player1);
            player1->removeInventory(player1->indexInInventory(playerPotion1) +
                                     1);

          } else if (playerPotion1->getID() == 32) {
            dynamic_cast<StaminaPotion*>(playerPotion1)
                ->increaseStamina(*player1);
            player1->removeInventory(player1->indexInInventory(playerPotion1) +
                                     1);

          } else if (playerPotion1->getID() == 33) {
            dynamic_cast<Food*>(playerPotion1)->increaseStats(*player1);
            player1->removeInventory(player1->indexInInventory(playerPotion1) +
                                     1);

          } else if (playerPotion1->getID() == 34) {
            dynamic_cast<SweetTea*>(playerPotion1)->increaseHP(*player1);
            player1->removeInventory(player1->indexInInventory(playerPotion1) +
                                     1);

          } else if (playerPotion1->getID() == 35) {
            dynamic_cast<Saffron*>(playerPotion1)->increaseDamage(*player1);
            player1->removeInventory(player1->indexInInventory(playerPotion1) +
                                     1);

          } else if (playerPotion1->getID() == 36) {
            dynamic_cast<AraghNana*>(playerPotion1)->increaseDefense(*player1);
            player1->removeInventory(player1->indexInInventory(playerPotion1) +
                                     1);

          } else if (playerPotion1->getID() == 37) {
            dynamic_cast<Nuts*>(playerPotion1)->increaseStamina(*player1);
            player1->removeInventory(player1->indexInInventory(playerPotion1) +
                                     1);
          }
          displayHealthBar(player1->getName(), player1->getCurrentHP(),
                           player1->getMaxHP());
          cout << endl;
          displayHealthBar(player2->getName(), player2->getCurrentHP(),
                           player2->getMaxHP());
        }
        break;
      }
      case 4: {
        clearScreen();
        checkInventory(player1);
        player1->showInventory();
        continue;
      }
    }
    // Check if player 2 is defeated
    if (player2->getCurrentHP() <= 0) {
      cout << player2->getName() << " has been defeated!" << endl;
      break;
    }

    displayHealthBar(player1->getName(), player1->getCurrentHP(),
                     player1->getMaxHP());
    cout << endl;
    displayHealthBar(player2->getName(), player2->getCurrentHP(),
                     player2->getMaxHP());

    if (choice2 == 2) {
      player2->setDefense(player2->getDefense() - defsynergy2);
    }

    // Player 2's turn
    cout << endl << player2->getName() << "'s Turn: " << endl;
    combatMenu(player2);
    cin >> choice2;
    switch (choice2) {
      case 0:
        easterEgg(player2);
        break;
      case 1: {
        clearScreen();
        synergy2 = player2->chooseAtkItem();
        player2->setAttack(player2->getAttack() + (int)synergy2);
        player2->performAttack(*player1);
        player2->setAttack(player2->getAttack() - (int)synergy2);
        break;
      }
      case 2: {
        clearScreen();
        defsynergy2 = player2->chooseDefItems();
        player2->setDefense(player2->getDefense() + defsynergy2);
        player2->performDefense(*player2);
        break;
      }
      case 3: {
        clearScreen();
        playerPotion2 = player2->choosePotion();
        if (playerPotion2 == nullptr) {
          continue;
        } else {
          if (playerPotion2->getID() == 29) {
            dynamic_cast<HealingPotion*>(playerPotion2)->increaseHP(*player2);
            player2->removeInventory(player2->indexInInventory(playerPotion2) +
                                     1);

          } else if (playerPotion2->getID() == 30) {
            dynamic_cast<DamagePotion*>(playerPotion2)
                ->increaseDamage(*player2);
            player2->removeInventory(player2->indexInInventory(playerPotion2) +
                                     1);

          } else if (playerPotion2->getID() == 31) {
            dynamic_cast<DefensePotion*>(playerPotion2)
                ->increaseDefense(*player2);
            player2->removeInventory(player2->indexInInventory(playerPotion2) +
                                     1);

          } else if (playerPotion2->getID() == 32) {
            dynamic_cast<StaminaPotion*>(playerPotion2)
                ->increaseStamina(*player2);
            player2->removeInventory(player2->indexInInventory(playerPotion2) +
                                     1);

          } else if (playerPotion2->getID() == 33) {
            dynamic_cast<Food*>(playerPotion2)->increaseStats(*player2);
            player2->removeInventory(player2->indexInInventory(playerPotion2) +
                                     1);

          } else if (playerPotion2->getID() == 34) {
            dynamic_cast<SweetTea*>(playerPotion2)->increaseHP(*player2);
            player2->removeInventory(player2->indexInInventory(playerPotion2) +
                                     1);

          } else if (playerPotion2->getID() == 35) {
            dynamic_cast<Saffron*>(playerPotion2)->increaseDamage(*player2);
            player2->removeInventory(player2->indexInInventory(playerPotion2) +
                                     1);

          } else if (playerPotion2->getID() == 36) {
            dynamic_cast<AraghNana*>(playerPotion2)->increaseDefense(*player2);
            player2->removeInventory(player2->indexInInventory(playerPotion2) +
                                     1);

          } else if (playerPotion2->getID() == 37) {
            dynamic_cast<Nuts*>(playerPotion2)->increaseStamina(*player2);
            player2->removeInventory(player2->indexInInventory(playerPotion2) +
                                     1);
          }
          displayHealthBar(player1->getName(), player1->getCurrentHP(),
                           player1->getMaxHP());
          cout << endl;
          displayHealthBar(player2->getName(), player2->getCurrentHP(),
                           player2->getMaxHP());
        }
        break;
      }
      case 4: {
        clearScreen();
        checkInventory(player2);
        player2->showInventory();
        continue;
      }
    }
    // Check if player 1 is defeated
    if (player1->getCurrentHP() <= 0) {
      cout << player1->getName() << " has been defeated!" << endl;
      break;
    }
    if (choice1 == 2) {
      player1->setDefense(player1->getDefense() - defsynergy1);
    }
    displayHealthBar(player1->getName(), player1->getCurrentHP(),
                     player1->getMaxHP());
    cout << endl;
    displayHealthBar(player2->getName(), player2->getCurrentHP(),
                     player2->getMaxHP());
  }
  cout << "\n*** Combat Ends ***\n" << endl;
  waitForEnter();
}

void explore(GameState& gameState,
             ScreenInteractive& screen,
             function<void()> return_to_menu) {
  srand(time(nullptr));    // Seed for random number generation
  int event = rand() % 4;  // Random event selection

  Human* player = gameState.getPlayerCharacter();
  characterType types[3] = {characterType::WEAKZOMBIE,
                            characterType::STRONGZOMBIE,
                            characterType::HUMANENEMY};
  characterType type = types[rand() % 3];
  Enemy* enemy = EnemyFactory::createEnemy(type, player->getLevel(), player);
  Item* potion = new HealingPotion("Elixir of Healing", 50.0, false, 50.0, 1);

  // Creating a container to hold both the message and the Back button
  auto container = Container::Vertical({
    Renderer([=, &screen, &gameState, &return_to_menu] {
      clearScreen();
      string message;
      switch (event) {
        case 0:
          player->addInventory(potion);
          message = "You found a healing potion on the ground.";
          break;
        case 1:
          player->takeDamage(10);
          if (player->getCurrentHP() <= 0) {
            message += " You died!";
            sleepMilliseconds(500);
            return_to_menu(); // Call return_to_menu if the player died.
          }
          message = "You encountered a trap! You lose 10 HP. Your health: " +
                    to_string((int)player->getCurrentHP()) + "/" +
                    to_string((int)player->getMaxHP()) + ".";
          break;
        case 2:
          player->setCoin(player->getCoin() + 50);
          message = "You found a hidden treasure chest containing 50 gold!";
          break;
        case 3:
          message = "You encountered " + enemy->getName() +
                    "! Prepare for combat!";
          break;
        default:
          message = "It's a peaceful walk. Nothing happens.";
          break;
      }
      return vbox({text("Exploring..."), text(message)}) | border;
    }),
    Button("Back", return_to_menu)
  });

  // If the player encountered an enemy, initiate combat after the screen updates.
  if (event == 3) {
    combat(player, enemy); // Call your combat function here.
    screen.ExitLoopClosure()();
  }

  // Display the exploration results with the back button
  screen.Loop(container);
}

void gameLoop(GameState& gameState) {
  auto screen = ScreenInteractive::TerminalOutput();

  while (!gameState
              .isGameOver()) {  // Loop to re-enter FTXUI menu after each action
    std::vector<std::string> menu_entries = {"Explore", "Shop", "View Stats",
                                             "Save Game", "Exit"};
    int selected_index = 0;

    // Create the menu component
    MenuOption option;
    option.on_enter = screen.ExitLoopClosure();
    auto menu = Menu(&menu_entries, &selected_index, option);

    // Run the UI loop
    screen.Loop(menu);

    // Handle the selected action outside of the UI loop
    switch (selected_index) {
      case 0:
        // explore(gameState);
        explore(gameState, screen, [&] { screen.ExitLoopClosure()(); });
        if (gameState.getPlayerCharacter()->getCurrentHP() <= 0) {
          playerDied(gameState.getPlayerCharacter());
        }
        break;
      case 1:
        handleShopInteraction(gameState);
        break;
      case 2:
        // showPlayerStats(gameState.getPlayerCharacter());
        showPlayerStats(screen, gameState.getPlayerCharacter());
        break;
      case 3:
        saveCharacter(gameState.getPlayerCharacter());
        showGameSavedMessage(screen);
        break;
      case 4:
        gameState.setGameOver(true);  // Set game over and exit the menu loop
        break;
    }
  }
}

void gameLoopMulti(GameStateMulti& gameState) {
  bool exitGame = false;
  while (!exitGame && !gameState.isGameOver()) {
    clearScreen();
    Shop& shop = gameState.getGameShop();
    cout << "First player, please enter the shop." << endl;
    shop.welcomeShop(gameState.getPlayer1Character());
    clearScreen();
    cout << "Second player, please enter the shop." << endl;
    shop.welcomeShop(gameState.getPlayer2Character());
    clearScreen();
    combatMulti(gameState.getPlayer1Character(),
                gameState.getPlayer2Character());
    clearScreen();
    cout << "Do you want to play again or exit the game? (p/e)" << endl;
    char choice;
    cin >> choice;
    while (choice != 'p' && choice != 'e') {
      cout << "Invalid choice. Please try again." << endl;
      cin >> choice;
    }
    if (choice == 'p') {
      cout << "Both players' inventorys will be earased and you will be "
              "redirected to the shop"
           << endl;
      sleepMilliseconds(5000);
      gameState.getPlayer1Character()->clearInventory();
      gameState.getPlayer2Character()->clearInventory();
      gameState.getPlayer1Character()->setCurrentHP(
      gameState.getPlayer1Character()->getMaxHP());
      gameState.getPlayer2Character()->setCurrentHP(
      gameState.getPlayer2Character()->getMaxHP());
      gameState.getPlayer1Character()->setCoin(5000);
      gameState.getPlayer2Character()->setCoin(5000);
      giveBasicItems(gameState.getPlayer1Character());
      giveBasicItems(gameState.getPlayer2Character());

    } else {
      gameState.setGameOver(true);
    }
  }
}

int main() {
  auto screen = ScreenInteractive::TerminalOutput();

  // Menu options
  std::vector<std::string> entries = {
      "Solo Player",
      "Multi Player",
  };
  int selected = 0;

  MenuOption option;
  option.on_enter = screen.ExitLoopClosure();

    auto menu = Menu(&entries, &selected, option);
 
  screen.Loop(menu);
 
  std::cout << "Selected element = " << selected << std::endl;;

  // Process the choice
  if (selected == 1) {  // Multiplayer
    clearScreen();
    vector<Human*> players = LoginMultiplayer();
    GameStateMulti gameStateMulti(players[0], players[1]);
    gameLoopMulti(gameStateMulti);
  } else {  // Single Player
    clearScreen();
    Human* playerCharacter = Login();
    GameState gameState(playerCharacter);
    gameLoop(gameState);
  }

  return 0;
}
