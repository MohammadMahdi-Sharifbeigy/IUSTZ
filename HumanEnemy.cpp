#include "HumanEnemy.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "ASCIIArt/ASCIIArts.h"
#include "Paladin.h"
#include "State.h"

// Utility function for generating a random number within a range
static int getRandomNumber(int min, int max) {
  std::random_device rd;
  std::mt19937 eng(rd());
  std::uniform_int_distribution<> distr(min, max);
  return distr(eng);
}

int AttachSynergy(Item* item) {
  int Synergy;
  if (item->getID() > 0 || item->getID() < 22) {
    Passive* itemType = static_cast<Passive*>(item);
    Synergy = itemType->getSynergyDamage();
  } else if (item->getID() > 29 || item->getID() < 38) {
    Throwable* itemType = dynamic_cast<Throwable*>(item);
    Synergy = itemType->getSynergyDmg();
  }
  return Synergy;
}

HumanEnemyModel::HumanEnemyModel(int level, Human& human)
    : Enemy(level),
      human(human),
      state(State::ATTACK),
      haveUsedAtkP(false),
      haveUsedDefP(false) {
  srand(static_cast<unsigned int>(time(nullptr)));
  attackStrategy = new HumanEnemyAttack();
  Character::name = "Human Enemy";
  level = abs(level + rand() % 4) + 1;
  int ran = (rand() % (5 * level / 4));
  maxHP = 2 * level + ran + 100;
  currHP = maxHP;
  attack = 4 * level + ran;
  defense = 2 * level + ran;
  role = getRandomRole();  // Set role randomly
  haveUsedAtkP = false;
  haveUsedDefP = false;
  Human* hum =
      new Paladin("name", 1, 100.0, 3.0, 5.0, characterType::PALADIN, 1000);
  int random = getRandomNumber(1, 6);
  Item* armor = ItemFactory::createItem(random, hum, true);
  this->addInventory(armor);
  random = getRandomNumber(8, 19);
  Item* weapon = ItemFactory::createItem(random, hum, true);
  this->addInventory(weapon);
  random = getRandomNumber(22, 27);
  Item* throwable = ItemFactory::createItem(random, hum, true);
  this->addInventory(throwable, 10);
  random = getRandomNumber(30, 31);
  Item* potion = ItemFactory::createItem(random, hum, true);
  this->addInventory(potion);
  Item* healingPotion = ItemFactory::createItem(29, hum, true);
  random = getRandomNumber(1, 2);
  this->addInventory(healingPotion, random);
}

HumanEnemyModel::~HumanEnemyModel() {
  delete attackStrategy;
  for (auto* item : inventory) {
    delete item;
  }
}

characterType HumanEnemyModel::getRandomRole() {
  return static_cast<characterType>(
      getRandomNumber(0, static_cast<int>(characterType::WIZARD)));
}

int HumanEnemyModel::inventorySize() {
  return inventory.size();
}

Item* HumanEnemyModel::itemsAt(int index) {
  if (this->inventorySize()) {
    return inventory.at(index - 1);
  }
  return nullptr;
}

void HumanEnemyModel::showInventory() {
  if (this->inventorySize() > 0) {
    for (int i = 0; i < inventory.size(); i++) {
      cout << i + 1 << ". " << inventory[i]->getName()
           << " - count:" << inventory[i]->getCount() << endl;
    }
  } else {
    cout << "Your inventory is empty!" << endl;
  }
}

void HumanEnemyModel::addInventory(Item* item) {
  int check = 0;
  if (this->inventorySize() > 0) {
    for (int i = 0; i < this->inventorySize(); i++) {
      if (item->getName() == inventory[i]->getName()) {
        inventory[i]->setCount(inventory[i]->getCount() + 1);
        check++;
        break;
      }
    }
    if (check == 0) {
      inventory.push_back(item);
      //  inventory[inventory.size()-1]->setCount(1);
    }

  } else {
    inventory.push_back(item);
    // inventory[inventory.size()-1]->setCount(1);
  }
}

void HumanEnemyModel::removeInventory(int index) {
  if (index - 1 < this->inventorySize()) {
    if (inventory[index - 1]->getCount() == 1) {
      inventory.erase(inventory.begin() + index - 1);
    } else {
      inventory[index - 1]->setCount(inventory[index - 1]->getCount() - 1);
    }
  }
}

void HumanEnemyModel::addInventory(Item* item, int count) {
  int check = 0;
  if (this->inventorySize() > 0) {
    for (int i = 0; i < this->inventorySize(); i++) {
      if (item->getName() == inventory[i]->getName()) {
        inventory[i]->setCount(inventory[i]->getCount() + count);
        check++;
        break;
      }
    }
    if (check == 0) {
      inventory.push_back(item);
      inventory[inventory.size() - 1]->setCount(count);
    }

  } else {
    inventory.push_back(item);
    inventory[inventory.size() - 1]->setCount(count);
  }
}

void HumanEnemyModel::removeInventory(int index, int count) {
  if (index - 1 < this->inventorySize()) {
    if (inventory[index - 1]->getCount() == count) {
      inventory.erase(inventory.begin() + index - 1);
    } else if (inventory[index - 1]->getCount() > count) {
      inventory[index - 1]->setCount(inventory[index - 1]->getCount() - count);
    } else {
      cout << "You hav only " << inventory[index - 1]->getCount() << " "
           << inventory[index - 1]->getName() << "s you can't remove " << count
           << endl;
    }
  }
}

bool HumanEnemyModel::existInInventory(Item* item) {
  for (int i = 0; i < this->inventory.size(); i++) {
    if (this->inventory[i]->getName() == item->getName()) {
      return true;
    }
  }
  return false;
}

int HumanEnemyModel::countInInventory(Item* item) {
  for (int i = 0; i < this->inventory.size(); i++) {
    if (this->inventory[i]->getName() == item->getName()) {
      return inventory[i]->getCount();
    }
  }
  return 0;
}

int HumanEnemyModel::indexInInventory(Item* item) {
  for (int i = 0; i < this->inventory.size(); i++) {
    if (this->inventory[i]->getName() == item->getName()) {
      return i;
    }
  }
  return -1;
}

double HumanEnemyModel::priceItemsAt(int index) {
  return inventory[index - 1]->getPrice();
}

int HumanEnemyModel::countItemsAt(int index) {
  return inventory[index - 1]->getCount();
}

void HumanEnemyModel::performAttack(Character& target) {
  if (attackStrategy) {
    // Get the character type of 'this' HumanEnemy
    characterType currHumanRole = this->getRole();
    // Determine the AttackType based on the target's role
    AttackType attackType = static_cast<HumanEnemyAttack*>(attackStrategy)
                                ->getAttackTypeForRole(target.getRole());
    // Apply the FSM to get modified attack and defense values
    std::pair<double, double> modifiedValues =
        static_cast<HumanEnemyAttack*>(attackStrategy)
            ->applyFSM(currHumanRole, &target, this, attackType);
    double modifiedAttack = modifiedValues.first;
    // Use the modified attack value to deal damage
    target.takeDamage(modifiedAttack);
  } else {
    std::cout << getcharType() << " attacks " << target.getName()
              << " with a basic attack." << std::endl;
    target.takeDamage(getAttack());
  }
}

void HumanEnemyModel::performDefense(Human& attacker) {
  if (attackStrategy) {
    // Get the character type of 'this' HumanEnemy
    characterType currHumanRole = this->getRole();
    // Determine the AttackType based on the attacker's role
    AttackType attackType = static_cast<HumanEnemyAttack*>(attackStrategy)
                                ->getAttackTypeForRole(attacker.getRole());
    // Apply the FSM to get modified attack and defense values
    std::pair<double, double> modifiedValues =
        static_cast<HumanEnemyAttack*>(attackStrategy)
            ->applyFSM(currHumanRole, &attacker, this, attackType);
    double modifiedDefense = modifiedValues.second;
    // Use the modified defense value to reduce damage taken
    takeDamage(modifiedDefense);
  } else {
    std::cout << getcharType() << " defends against " << attacker.getName()
              << " with a basic defense." << std::endl;
    takeDamage(attacker.getAttack());
  }
}

State HumanEnemyModel::getState() {
  return state;
}

void HumanEnemyModel::setState(State state) {
  this->state = state;
}

void HumanEnemyModel::setStateBasedOnHP() {
  if (this->currHP < (this->maxHP * 20) / 100) {
    setState(NEARDEATH);
  } else if (this->currHP < (this->maxHP * 50) / 100) {
    setState(DEFENSE);
  } else {
    setState(ATTACK);
  }
}
bool HumanEnemyModel::useHealingPotion() {
  Human* hum =
      new Paladin("name", 1, 100.0, 3.0, 5.0, characterType::PALADIN, 1000);
  Item* healingPotion = ItemFactory::createItem(29, hum, true);
  int count = countInInventory(healingPotion);
  int index = indexInInventory(healingPotion);
  if (count > 0) {
    setCurrentHP(getCurrentHP() + ((getMaxHP() * 10) / 100));
    cout << "Enemy's HP has increased by " << (getMaxHP() * 10) / 100
         << " points." << endl;
    cout << "Enemy's current HP: " << getCurrentHP() + ((getMaxHP() * 10) / 100)
         << endl;
    removeInventory(index + 1);
    return true;
  }
  return false;
}

bool HumanEnemyModel::useAttackPotion() {
  Human* hum =
      new Paladin("name", 1, 100.0, 3.0, 5.0, characterType::PALADIN, 1000);
  Item* attackPotion = ItemFactory::createItem(30, hum, true);
  int count = countInInventory(attackPotion);
  int index = indexInInventory(attackPotion);
  if (count > 0) {
    set_enemy_atk(get_enemy_atk() + ((get_enemy_atk() * 20) / 100));
    cout << "Enemy's attack has increased by " << (get_enemy_atk() * 20) / 100
         << " points." << endl;
    removeInventory(index + 1);
    this->haveUsedAtkP = true;
    return true;
  }
  return false;
}

bool HumanEnemyModel::useDefensePotion() {
  Human* hum =
      new Paladin("name", 1, 100.0, 3.0, 5.0, characterType::PALADIN, 1000);
  Item* defensePotion = ItemFactory::createItem(31, hum, true);
  int count = countInInventory(defensePotion);
  int index = indexInInventory(defensePotion);
  if (count > 0) {
    set_enemy_def(get_enemy_def() + ((get_enemy_def() * 20) / 100));
    cout << "Enemy's defense has increased by " << (get_enemy_def() * 20) / 100
         << " points." << endl;
    removeInventory(index + 1);
    this->haveUsedDefP = true;
    return true;
  }
  return false;
}

double HumanEnemyModel::useAtkItem(bool dontUse) {
  double synergy = 0;
  if (dontUse) {
    int random = rand() % 4;
    if (random == 0) {
      if (inventory[1]->getID() > 0 || inventory[1]->getID() < 22) {
        synergy = AttachSynergy(inventory[1]);
        cout << "Enemy used " << inventory[1]->getName() << " to attack you"
             << endl;
      }
    } else if (random == 1) {
      if (this->inventory.size() > 2) {
        int ID = this->inventory[2]->getID();
        if (ID > 21 && ID < 28) {
          synergy = AttachSynergy(inventory[2]);
          cout << "Enemy used " << inventory[2]->getName() << " to attack you."
               << endl;
          removeInventory(2);
        } else {
          if (inventory[1]->getID() > 0 || inventory[1]->getID() < 22) {
            synergy = AttachSynergy(inventory[1]);
            cout << "Enemy used " << inventory[1]->getName() << " to attack you"
                 << endl;
          }
        }
      } else {
        if (inventory[1]->getID() > 0 || inventory[1]->getID() < 22) {
          synergy = AttachSynergy(inventory[1]);
          cout << "Enemy used " << inventory[1]->getName() << " to attack you"
               << endl;
        }
      }
    } else {
      synergy = 0;
    }
  } else {
    int random = rand() % 2;
    if (random == 0) {
      if (inventory[1]->getID() > 0 || inventory[1]->getID() < 22) {
        synergy = AttachSynergy(inventory[1]);
        cout << "Enemy used " << inventory[1]->getName() << " to attack you"
             << endl;
      }
    } else {
      if (this->inventory.size() > 2) {
        int ID = this->inventory[2]->getID();
        if (ID > 21 && ID < 28) {
          synergy = AttachSynergy(inventory[2]);
          cout << "Enemy used " << inventory[2]->getName() << " to attack you."
               << endl;
          removeInventory(2);
        } else {
          if (inventory[1]->getID() > 0 || inventory[1]->getID() < 22) {
            synergy = AttachSynergy(inventory[1]);
            cout << "Enemy used " << inventory[1]->getName() << " to attack you"
                 << endl;
          }
        }
      } else {
        if (inventory[1]->getID() > 0 || inventory[1]->getID() < 22) {
          synergy = AttachSynergy(inventory[1]);
          cout << "Enemy used " << inventory[1]->getName() << " to attack you"
               << endl;
        }
      }
    }
  }
  synergy = (synergy * 60) / 100;
  if (synergy > 6) {
    synergy = 6;
  }
  return synergy;
}

double HumanEnemyModel::useDefItem(bool dontUse) {
  double synergy = 0;
  if (dontUse) {
    int random = rand() % 2;
    if (random == 0) {
      if (inventory[0]->getID() > 0 || inventory[0]->getID() < 22) {
        synergy = AttachSynergy(inventory[0]);
        cout << "Enemy used " << inventory[0]->getName() << " to defense"
             << endl;
      }
    } else {
      synergy = 0;
    }
  } else {
    if (inventory[0]->getID() > 0 || inventory[0]->getID() < 22) {
      synergy = AttachSynergy(inventory[0]);
      cout << "Enemy used " << inventory[0]->getName() << " to defense" << endl;
    }
  }
  synergy = (synergy * 60) / 100;
  if (synergy > 6) {
    synergy = 6;
  }
  return synergy;
}

void HumanEnemyModel::atkInUpdate(Human& target, bool dont) {
  double synergy = useAtkItem(dont);
  this->attack += (int)synergy;
  performAttack(target);
  this->attack -= (int)synergy;
}

void HumanEnemyModel::defInUpdate(Human& target, bool dont) {
  double synergy = useDefItem(true);
  this->defense += (int)synergy;
  Human* humanTarget = dynamic_cast<Human*>(&target);
  performDefense(*humanTarget);
  this->defense -= (int)synergy;
}

void HumanEnemyModel::Update(Human& target) {
  setStateBasedOnHP();
  switch (this->state) {
    case State::ATTACK: {
      if (target.getState() == State::NEARDEATH) {
        atkInUpdate(target, false);
      } else {
        int random = rand() % 4;
        if (random == 0) {
          defInUpdate(target, true);

        } else {
          atkInUpdate(target, true);
        }
        setStateBasedOnHP();
      }
      break;
    }
    case State::DEFENSE: {
      bool atk = useAttackPotion();
      bool def = useDefensePotion();
      if (target.getState() == State::NEARDEATH) {
        atkInUpdate(target, false);
      } else {
        if (!atk && !def) {
          int random = rand() % 5;
          if (this->haveUsedAtkP) {
            if (random == 0 || random == 1) {
              defInUpdate(target, false);

            } else {
              atkInUpdate(target, true);
            }

          } else if (this->haveUsedDefP) {
            if (random == 0 || random == 1) {
              atkInUpdate(target, false);

            } else {
              defInUpdate(target, true);
            }

          } else {
            if (random == 0 || random == 1) {
              atkInUpdate(target, false);

            } else {
              defInUpdate(target, false);
            }
          }
        }
        setStateBasedOnHP();
      }
      break;
    }
    case State::NEARDEATH: {
      bool healing = useHealingPotion();
      if (!healing) {
        if (target.getState() == State::NEARDEATH) {
          atkInUpdate(target, false);
        } else {
          int random = rand() % 2;
          if (random == 0) {
            atkInUpdate(target, false);
          } else {
            defInUpdate(target, false);
          }
        }
      }
      setStateBasedOnHP();
      break;
    }
  }
}

// View

// Constructor definition
HumanEnemyView::HumanEnemyView() {
  // Constructor implementation (if any)
}

// Method to display human enemy details
void HumanEnemyView::displayHumanEnemy(HumanEnemyModel* humanEnemy) {
  std::cout << "Human Enemy created with Type: " << humanEnemy->getRole()
            << std::endl;
  characterType Role = humanEnemy->getRole();
  if (Role == PALADIN) {
    cout << Paladin1 << endl;
  } else if (Role == SUPERHERO) {
    cout << Superhero2 << endl;
  } else if (Role == ASSASSIN) {
    cout << Assassin << endl;
  } else if (Role == CYBORG) {
    cout << Cyborg << endl;
  } else if (Role == SNIPER) {
    cout << Sniper << endl;
  } else if (Role == ASIANMOM) {
    cout << AsianMom << endl;
  } else if (Role == WIZARD) {
    cout << Wizard << endl;
  }
}

// Controller
HumanEnemyController::HumanEnemyController(HumanEnemyModel& model,
                                           HumanEnemyView& view)
    : model(model), view(view) {}

void HumanEnemyController::PerformAttack(Character& target) {
  model.performAttack(target);
}

void HumanEnemyController::PerformDefense(Human& attacker) {
  model.performDefense(attacker);
}
