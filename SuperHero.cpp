#include "SuperHero.h"
#include <fstream>
#include <iostream>
#include "AttackStrategy.h"
#include "Character.h"
#include "CharacterType.h"
#include "FileCheck.h"
#include "Human.h"
#include "ItemFactory.h"

using namespace std;

SuperHero::SuperHero(const string& name,
                     int age,
                     double hp,
                     double defense,
                     double attack,
                     characterType role,
                     int coin)
    : Human(name, age, hp, attack, defense, role) {
  attackStrategy = new SuperHeroAttack();
  age = 1;
  maxHP = 100.0;
  currHP = 100.0;
  maxXP = 100;
  currXP = 0;
  stamina = 100.0;
  strength = 10.0;
  endurance = 10.0;
  accuracy = 10.0;
  pace = 10.0;
  mind = 10.0;
  this->coin = coin;
}

SuperHero::~SuperHero() {
  delete attackStrategy;
}

void SuperHero::performAttack(Character& target) {
  if (attackStrategy) {
    Enemy* enemy = dynamic_cast<Enemy*>(&target);
    if (enemy) {
      double damage = attackStrategy->attackEnemy(this, enemy);
      enemy->takeDamage(damage);
      cout << getName() << " dealt " << damage << " damage to "
           << target.getName() << endl;
    }
  } else {
    cout << getName() << " attacks " << target.getcharType()
         << " with a basic attack." << endl;
    Enemy* enemy = dynamic_cast<Enemy*>(&target);
    if (enemy) {
      enemy->takeDamage(SuperHero::getAttack());
    }
  }
}

void SuperHero::performAttack(Human& target) {
  if (attackStrategy) {
    if (&target) {
      double damage = attackStrategy->attackOpponent(this, &target);
      target.takeDamage(damage);
      cout << getName() << " dealt " << damage << " damage to "
           << target.getName() << endl;
    }
  } else {
    cout << getName() << " attacks " << target.getName()
         << " with a basic attack." << endl;
    if (&target) {
      target.takeDamage(this->getAttack());
    }
  }
}

void SuperHero::performDefense(Character& attacker) {
  Enemy* enemy = dynamic_cast<Enemy*>(&attacker);
  if (attackStrategy) {
    if (enemy) {
      double defense = attacker.getAttack() - attackStrategy->defenseEnemy(this, enemy);
      SuperHero::takeDamage(defense);
      cout << SuperHero::getName() << " got defended by " << defense
           << " armor." << endl;
    }
  } else {
    SuperHero::takeDamage((enemy->get_enemy_atk() - SuperHero::getDefense()));
    cout << getName() << " defends against " << attacker.getcharType()
         << " with a basic defense." << endl;
  }
}

void SuperHero::performDefense(Human& attacker) {
  if (attackStrategy) {
    if (&attacker) {
      double defense = attacker.getAttack() - attackStrategy->defenseOpponent(this, &attacker);
      if (attacker.getAttack() >= defense) {
        SuperHero::takeDamage(defense);
      }
      cout << SuperHero::getName() << " got defended by " << defense
           << " armor." << endl;
    }
  } else {
    SuperHero::takeDamage(attacker.getAttack() - SuperHero::getDefense());
    cout << getName() << " defends against " << attacker.getName()
         << " with a basic defense." << endl;
  }
}

void SuperHero::levelUp() {
  while (getCurrXP() >= getMaxXP()) {
    cout << "You have leveled up!" << endl;
    setMaxHP(getMaxHP() + 30);       // Moderate HP increase
    setAttack(getAttack() + 5);      // Superheroes have strong attacks
    setDefense(getDefense() + 3.5);  // Moderate defense increase
    setLevel(getLevel() + 1);
    setStamina(getStamina() + 15);
    setStrength(getStrength() + 2);
    setEndurance(getEndurance() + 2);
    setAccuracy(getAccuracy() + 2);
    setPace(getPace() + 2);
    setMind(getMind() + 2);
    setMaxXP(getMaxXP() + 75);

    cout << "Your level is now " << getLevel() << "!" << endl;
  }
}

inline characterType StringToCharacterType(const string& str) {
  if (str == "Paladin")
    return PALADIN;
  else if (str == "SuperHero")
    return SUPERHERO;
  else if (str == "Assassin")
    return ASSASSIN;
  else if (str == "AsianMom")
    return ASIANMOM;
  else if (str == "Cyborg")
    return CYBORG;
  else if (str == "sniper")
    return SNIPER;
  else if (str == "Wizard") {
    return WIZARD;
  } else
    return STRONGZOMBIE;
}

inline string CharacterTypeToString(const characterType& type) {
  switch (type) {
    case PALADIN:
      return "Paladin";
    case SUPERHERO:
      return "SupeHero";
    case ASSASSIN:
      return "Assassin";
    case ASIANMOM:
      return "AsianMom";
    case CYBORG:
      return "Cyborg";
    case SNIPER:
      return "Sniper";
    case WIZARD:
      return "Wizard";
    default:
      return "UNKNOWN";
  }
}

static int itemID(Item* item) {
  if (item == nullptr) {
    return -1;
  } else {
    return item->getID();
  }
}

static bool isCSV(const string& fileName) {
  size_t pos = fileName.rfind(".csv");
  if (pos != string::npos && pos == fileName.length() - 4) {
    return true;
  }
  return false;
}

void SuperHero::SuperHeroToFile(const string& username) {
  string filename = isCSV(username) ? username : username + ".csv";
  ofstream file(filename);

  // Write the header
  file << "username,name,age,role,level,coin,currHP,currXP,maxHP,maxXP,attack,"
          "defense,stamina,armorID,weaponID,strength,endurance,accuracy,pace,"
          "mind,inventorySize"
       << "\n";

  // Write the character data in one line
  file << this->username << ',' << this->name << ',' << this->age << ','
       << CharacterTypeToString(this->role) << ',' << this->level << ','
       << this->coin << ',' << this->currHP << ',' << this->currXP << ','
       << this->maxHP << ',' << this->maxXP << ',' << this->attack << ','
       << this->defense << ',' << this->stamina << ',' << itemID(this->armor)
       << ',' << itemID(this->weapon) << ',' << this->strength << ','
       << this->endurance << ',' << this->accuracy << ',' << this->pace << ','
       << this->mind << ',' << this->inventorySize();

  if (this->inventorySize() > 0) {
    for (int i = 0; i < this->inventorySize(); i++) {
      file << ',' << inventory[i]->getID() << ',' << inventory[i]->getCount();
    }
  }

  file << '\n';

  ifstream users("usernames.csv");
  string line;
  bool exists = false;
  while (getline(users, line)) {
    if (line.find(username + ",SuperHero") != string::npos) {
      exists = true;
      break;
    }
  }
  users.close();

  if (!exists) {
    ofstream usersfile("usernames.csv", ios::app);
    usersfile << username << ",SuperHero\n";
    usersfile.close();
  }
  file.close();
}

void SuperHero::FileToSuperHero(const string& username) {
  string filename = isCSV(username) ? username : username + ".csv";
  ifstream file(filename);

  if (file.good() && !std::filesystem::is_empty(filename)) {
    string line;
    getline(file, line);  // Skip the header line
    getline(file, line);  // Read the data line

    stringstream ss(line);
    string attribute;

    // Parsing basic attributes
    getline(ss, this->username, ',');
    getline(ss, this->name, ',');
    getline(ss, attribute, ',');
    this->age = stoi(attribute);
    getline(ss, attribute, ',');
    this->role = StringToCharacterType(attribute);
    getline(ss, attribute, ',');
    this->level = stoi(attribute);
    getline(ss, attribute, ',');
    this->coin = stoi(attribute);
    getline(ss, attribute, ',');
    this->currHP = stof(attribute);
    getline(ss, attribute, ',');
    this->currXP = stoi(attribute);
    getline(ss, attribute, ',');
    this->maxHP = stof(attribute);
    getline(ss, attribute, ',');
    this->maxXP = stoi(attribute);
    getline(ss, attribute, ',');
    this->attack = stof(attribute);
    getline(ss, attribute, ',');
    this->defense = stof(attribute);
    getline(ss, attribute, ',');
    this->stamina = stof(attribute);

    // Correct handling for armor
    getline(ss, attribute, ',');
    if (attribute == "-1") {
      this->armor = nullptr;
    } else {
      this->armor = ItemFactory::createItem(stoi(attribute), this, true);
      this->armor->setCount(1);
    }

    // Correct handling for weapon
    getline(ss, attribute, ',');
    if (attribute == "-1") {
      this->weapon = nullptr;
    } else {
      this->weapon = ItemFactory::createItem(stoi(attribute), this, false);
      this->weapon->setCount(1);
    }

    // Parsing additional attributes
    getline(ss, attribute, ',');
    this->strength = stof(attribute);
    getline(ss, attribute, ',');
    this->endurance = stof(attribute);
    getline(ss, attribute, ',');
    this->accuracy = stof(attribute);
    getline(ss, attribute, ',');
    this->pace = stof(attribute);
    getline(ss, attribute, ',');
    this->mind = stof(attribute);

    // Handling inventory efficiently
    int n;
    getline(ss, attribute, ',');  // Inventory size
    n = stoi(attribute);
    for (int i = 0; i < n; ++i) {
      getline(ss, attribute, ',');
      int ID = stoi(attribute);
      getline(ss, attribute, ',');
      int count = stoi(attribute);

      Item* item = ItemFactory::createItem(ID, this, true);
      item->setCount(count);
      this->addInventory(item);
    }
  } else {
    this->name = "Error404";
    this->age = 0;
  }
  file.close();
}

// double convertedPrice = atof(sprice.c_str());
// if (vip == "true")
// {
//   Item *item = Item(name, price, true, count);
//   inventory.push_back(item);
// }
// else
// {
//   Item *item = Item(name, price, false, count);
//   inventory.push_back(item);
// }
