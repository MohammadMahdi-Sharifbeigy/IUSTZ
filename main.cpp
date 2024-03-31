#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include "Character.h"
#include "Enemy.h"
#include "GameState.h"
#include "HealingPotion.h"
#include "Paladin.h"
#include "Shop.h"
#include "Sword.h"
#include "Zombie.h"
#include "Login.cpp"

using namespace std;

const string You_Died = R"(
                                              ▓██   ██▓ ▒█████   █    ██    ▓█████▄  ██▓▓█████ ▓█████▄ 
                                               ▒██  ██▒▒██▒  ██▒ ██  ▓██▒   ▒██▀ ██▌▓██▒▓█   ▀ ▒██▀ ██▌
                                                ▒██ ██░▒██░  ██▒▓██  ▒██░   ░██   █▌▒██▒▒███   ░██   █▌
                                                ░ ▐██▓░▒██   ██░▓▓█  ░██░   ░▓█▄   ▌░██░▒▓█  ▄ ░▓█▄   ▌
                                                ░ ██▒▓░░ ████▓▒░▒▒█████▓    ░▒████▓ ░██░░▒████▒░▒████▓ 
                                                 ██▒▒▒ ░ ▒░▒░▒░ ░▒▓▒ ▒ ▒     ▒▒▓  ▒ ░▓  ░░ ▒░ ░ ▒▒▓  ▒ 
                                               ▓██ ░▒░   ░ ▒ ▒░ ░░▒░ ░ ░     ░ ▒  ▒  ▒ ░ ░ ░  ░ ░ ▒  ▒ 
                                               ▒ ▒ ░░  ░ ░ ░ ▒   ░░░ ░ ░     ░ ░  ░  ▒ ░   ░    ░ ░  ░ 
                                               ░ ░         ░ ░     ░           ░     ░     ░  ░   ░    
                                               ░ ░                           ░                  ░       
)";
const string Wasted = R"(
                                                    ▄▄▌ ▐ ▄▌ ▄▄▄· .▄▄ · ▄▄▄▄▄▄▄▄ .·▄▄▄▄  
                                                    ██· █▌▐█▐█ ▀█ ▐█ ▀. •██  ▀▄.▀·██▪ ██ 
                                                    ██▪▐█▐▐▌▄█▀▀█ ▄▀▀▀█▄ ▐█.▪▐▀▀▪▄▐█· ▐█▌
                                                    ▐█▌██▐█▌▐█ ▪▐▌▐█▄▪▐█ ▐█▌·▐█▄▄▌██. ██ 
                                                     ▀▀▀▀ ▀▪ ▀  ▀  ▀▀▀▀  ▀▀▀  ▀▀▀ ▀▀▀▀▀• 
)";
const string You_fallen = R"(
                           ▓██   ██▓ ▒█████   █    ██  ██▒   █▓▓█████      █████▒▄▄▄       ██▓     ██▓    ▓█████  ███▄    █ 
                            ▒██  ██▒▒██▒  ██▒ ██  ▓██▒▓██░   █▒▓█   ▀    ▓██   ▒▒████▄    ▓██▒    ▓██▒    ▓█   ▀  ██ ▀█   █ 
                             ▒██ ██░▒██░  ██▒▓██  ▒██░ ▓██  █▒░▒███      ▒████ ░▒██  ▀█▄  ▒██░    ▒██░    ▒███   ▓██  ▀█ ██▒
                             ░ ▐██▓░▒██   ██░▓▓█  ░██░  ▒██ █░░▒▓█  ▄    ░▓█▒  ░░██▄▄▄▄██ ▒██░    ▒██░    ▒▓█  ▄ ▓██▒  ▐▌██▒
                             ░ ██▒▓░░ ████▓▒░▒▒█████▓    ▒▀█░  ░▒████▒   ░▒█░    ▓█   ▓██▒░██████▒░██████▒░▒████▒▒██░   ▓██░
                              ██▒▒▒ ░ ▒░▒░▒░ ░▒▓▒ ▒ ▒    ░ ▐░  ░░ ▒░ ░    ▒ ░    ▒▒   ▓▒█░░ ▒░▓  ░░ ▒░▓  ░░░ ▒░ ░░ ▒░   ▒ ▒ 
                            ▓██ ░▒░   ░ ▒ ▒░ ░░▒░ ░ ░    ░ ░░   ░ ░  ░    ░       ▒   ▒▒ ░░ ░ ▒  ░░ ░ ▒  ░ ░ ░  ░░ ░░   ░ ▒░
                            ▒ ▒ ░░  ░ ░ ░ ▒   ░░░ ░ ░      ░░     ░       ░ ░     ░   ▒     ░ ░     ░ ░      ░      ░   ░ ░ 
                            ░ ░         ░ ░     ░           ░     ░  ░                ░  ░    ░  ░    ░  ░   ░  ░         ░ 
                            ░ ░                            ░                                                                
)";
const string TryAgain = R"(
                                 ▄▄▄█████▓ ██▀███ ▓██   ██▓    ▄▄▄        ▄████  ▄▄▄       ██▓ ███▄    █  ▐██▌ 
                                 ▓  ██▒ ▓▒▓██ ▒ ██▒▒██  ██▒   ▒████▄     ██▒ ▀█▒▒████▄    ▓██▒ ██ ▀█   █  ▐██▌ 
                                 ▒ ▓██░ ▒░▓██ ░▄█ ▒ ▒██ ██░   ▒██  ▀█▄  ▒██░▄▄▄░▒██  ▀█▄  ▒██▒▓██  ▀█ ██▒ ▐██▌ 
                                 ░ ▓██▓ ░ ▒██▀▀█▄   ░ ▐██▓░   ░██▄▄▄▄██ ░▓█  ██▓░██▄▄▄▄██ ░██░▓██▒  ▐▌██▒ ▓██▒ 
                                   ▒██▒ ░ ░██▓ ▒██▒ ░ ██▒▓░    ▓█   ▓██▒░▒▓███▀▒ ▓█   ▓██▒░██░▒██░   ▓██░ ▒▄▄  
                                   ▒ ░░   ░ ▒▓ ░▒▓░  ██▒▒▒     ▒▒   ▓▒█░ ░▒   ▒  ▒▒   ▓▒█░░▓  ░ ▒░   ▒ ▒  ░▀▀▒ 
                                     ░      ░▒ ░ ▒░▓██ ░▒░      ▒   ▒▒ ░  ░   ░   ▒   ▒▒ ░ ▒ ░░ ░░   ░ ▒░ ░  ░ 
                                   ░        ░░   ░ ▒ ▒ ░░       ░   ▒   ░ ░   ░   ░   ▒    ▒ ░   ░   ░ ░     ░ 
                                             ░     ░ ░              ░  ░      ░       ░  ░ ░           ░  ░    
                                                   ░ ░                                                         
)";
const string well2 = R"(

                                  ██╗    ██╗███████╗██╗     ██╗         ██████╗  ██████╗ ███╗   ██╗███████╗          
                                  ██║    ██║██╔════╝██║     ██║         ██╔══██╗██╔═══██╗████╗  ██║██╔════╝          
                                  ██║ █╗ ██║█████╗  ██║     ██║         ██║  ██║██║   ██║██╔██╗ ██║█████╗            
                                  ██║███╗██║██╔══╝  ██║     ██║         ██║  ██║██║   ██║██║╚██╗██║██╔══╝            
                        ██╗██╗    ╚███╔███╔╝███████╗███████╗███████╗    ██████╔╝╚██████╔╝██║ ╚████║███████╗    ██╗██╗
                        ╚═╝╚═╝     ╚══╝╚══╝ ╚══════╝╚══════╝╚══════╝    ╚═════╝  ╚═════╝ ╚═╝  ╚═══╝╚══════╝    ╚═╝╚═╝
)";
const string Well = R"(
                                               █     █░▓█████  ██▓     ██▓       ▓█████▄  ▒█████   ███▄    █ ▓█████              
                                              ▓█░ █ ░█░▓█   ▀ ▓██▒    ▓██▒       ▒██▀ ██▌▒██▒  ██▒ ██ ▀█   █ ▓█   ▀              
                                              ▒█░ █ ░█ ▒███   ▒██░    ▒██░       ░██   █▌▒██░  ██▒▓██  ▀█ ██▒▒███                
                                              ░█░ █ ░█ ▒▓█  ▄ ▒██░    ▒██░       ░▓█▄   ▌▒██   ██░▓██▒  ▐▌██▒▒▓█  ▄              
                                  ██▓  ██▓    ░░██▒██▓ ░▒████▒░██████▒░██████▒   ░▒████▓ ░ ████▓▒░▒██░   ▓██░░▒████▒    ██▓  ██▓ 
                                  ▒▓▒  ▒▓▒    ░ ▓░▒ ▒  ░░ ▒░ ░░ ▒░▓  ░░ ▒░▓  ░    ▒▒▓  ▒ ░ ▒░▒░▒░ ░ ▒░   ▒ ▒ ░░ ▒░ ░    ▒▓▒  ▒▓▒ 
                                  ░▒   ░▒       ▒ ░ ░   ░ ░  ░░ ░ ▒  ░░ ░ ▒  ░    ░ ▒  ▒   ░ ▒ ▒░ ░ ░░   ░ ▒░ ░ ░  ░    ░▒   ░▒  
                                  ░    ░        ░   ░     ░     ░ ░     ░ ░       ░ ░  ░ ░ ░ ░ ▒     ░   ░ ░    ░       ░    ░   
                                   ░    ░         ░       ░  ░    ░  ░    ░  ░      ░        ░ ░           ░    ░  ░     ░    ░  
                                   ░    ░                                         ░                                      ░    ░  
)";

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
  cout << "\nPlayer Stats:" << endl;
  cout << "HP: " << player->getCurrentHP() << "/" << player->getMaxHP() << endl;
  cout << "Attack: " << player->getAttack() << endl;
  cout << "Defense: " << player->getDefense() << endl;
  cout << "Gold: " << player->getCoin() << endl;
}

void handleShopInteraction(GameState& gameState) {
  Shop& shop = gameState.getGameShop();
  cout << "\n--- Shop ---\n";
  shop.buyItem(gameState.getPlayerCharacter());
}

void handleInventoryInteraction(GameState& gameState) {
  Human* player = gameState.getPlayerCharacter();

  cout << "\nYour items:\n";
  player->showInventory();

  int choice;
  cout << "0 to exit ";
  cin >> choice;
  if (choice == 0) {
    return;
  } else {
    cout << "Invalid choice. Please try again.\n";
  }
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
  int enemy_max_hp = enemy->get_enemy_hp();
  cout << "\nA wild " << enemy->getName() << " appears!\n" << endl;
  displayHealthBar(player->getName(), player->getCurrentHP(),
                   player->getMaxHP());
  cout << endl;
  displayHealthBar(enemy->getName(), enemy->get_enemy_hp(), enemy_max_hp);
  while (player->getCurrentHP() > 0 && enemy->get_enemy_hp() > 0) {
    combatMenu(player);
    int choice;
    cin >> choice;
    switch (choice) {
      case 1:
        enemy->takeDamage(player->getAttack());
        cout << player->getName() << " attacks! " << enemy->getName() << "has "
             << enemy->get_enemy_hp() << " health left." << endl;
        break;
      case 2:
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
        } else {
          cout << "You have no potions." << endl;
        }
        break;
      case 3:
        player->showInventory();
        continue;  // Skip enemy's turn
    }

    if (enemy->get_enemy_hp() <= 0) {
      cout << "\nYou defeated the " << enemy->getName() << "!" << endl;
      cout << endl
           << "\033[38;2;45;220;45m" << well2 << "\033[38;2;255;255;255m";
      break;
    }

    // Enemy's turn to attack
    player->takeDamage(enemy->get_enemy_atk());
    cout << enemy->getName() << " attacks! " << player->getName() << " has "
         << player->getCurrentHP() << " HP left." << endl;
    if (player->getCurrentHP() <= 0) {
      cout << endl << "\033[38;5;52m" << You_Died << "\033[38;5;232m";
      return;
    }
    displayHealthBar(player->getName(), player->getCurrentHP(),
                     player->getMaxHP());
    cout << endl;
    displayHealthBar(enemy->getName(), enemy->get_enemy_hp(), enemy_max_hp);
  }
}

void explore(GameState& gameState) {
  srand(time(nullptr));    // Seed for random number generation
  int event = rand() % 4;  // Random event: 0, 1, or 2

  Human* player = gameState.getPlayerCharacter();
  Enemy zombie(player->getLevel());
  zombie.setName("Zombie");
  Item* potion = new HealingPotion("Healing Potion", 50.0, false, 50.0, 1);
  switch (event) {
    case 0:
      cout << "You found a healing potion on the ground." << endl;
      player->addInventory(potion);
      break;
    case 1:
      cout << "You encountered a trap! You lose 10 HP." << endl;
      player->takeDamage(10);
      break;
    case 2:
      cout << "You found a hidden treasure chest containing 50 gold!" << endl;
      player->setCoin(player->getCoin() + 50);
      break;
    case 3:
      combat(gameState.getPlayerCharacter(), &zombie);
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
        handleInventoryInteraction(gameState);
        break;
      case 4:
        cout << "Exiting game.\n";
        exitGame = true;
        break;
      default:
        cout << "Invalid choice, please try again.\n";
    }
  }
}

int main() {
  // Initialize a player character with some gold
  Human* playerCharacter = Login();
      // new Paladin("Player", 18, 100.0, 3.0, 5.0, characterType::PALADIN, 1000);
  GameState gameState(playerCharacter);
  gameLoop(gameState);

  cout << "Game Over. Thanks for playing!\n";

  return 0;
}
