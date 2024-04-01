#include "Cyborg.h"
#include <fstream>
#include <iostream>
#include <string>
#include "AttackStrategy.h"
#include "Character.h"
#include "CharacterType.h"
#include "Enemy.h"
#include "FileCheck.h"
#include "Human.h"
#include "ItemFactory.h"

using namespace std;

Cyborg::Cyborg(const string& name,
               int age,
               double hp,
               double defense,
               double attack,
               characterType role,
               int coin)
    : Human(name, age, hp, attack, defense, role) {
  attackStrategy = new CyborgAttack();
  age = 1;
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

Cyborg::~Cyborg() {
  delete attackStrategy;
}

void Cyborg::performAttack(Character& target) {
  if (attackStrategy) {
    Enemy* enemy = dynamic_cast<Enemy*>(&target);
    if (enemy) {
      double damage = attackStrategy->attackEnemy(this, enemy);
      // enemy->set_enemy_hp(damage);
      enemy->takeDamage(damage);
    }
  } else {
    cout << getName() << " attacks " << target.getcharType()
         << " with a basic attack." << endl;
    Enemy* enemy = dynamic_cast<Enemy*>(&target);
    if (enemy) {
      enemy->set_enemy_hp(Cyborg::getAttack());
      // enemy->takeDamage(Cyborg::getAttack());
    }
  }
}

void Cyborg::performDefense(Character& attacker) {
  if (attackStrategy) {
    if (Enemy* enemy = dynamic_cast<Enemy*>(&attacker)) {
      double damage = attackStrategy->defenseEnemy(this, enemy);
      Cyborg::currHP -= damage;
    }
  } else {
    Cyborg::currHP -= Cyborg::getDefense();
    cout << getName() << " defends against " << attacker.getcharType()
         << " with a basic defense." << endl;
  }
}

void Cyborg::levelUp() {
  while (getCurrentXP() >= getMaxXP()) {
    cout << "You have leveled up!" << endl;
    setMaxHP(getMaxHP() +
             40);  // Cyborgs have high HP due to their mechanical nature
    setAttack(getAttack() +
              15);  // High attack increase due to advanced weaponry
    setDefense(getDefense() + 10);  // High defense increase due to armored body
    setLevel(getLevel() + 1);
    setStamina(getStamina() + 15);
    setStrength(getStrength() + 2);
    setEndurance(getEndurance() + 2);
    setAccuracy(getAccuracy() + 2);
    setPace(getPace() + 2);
    setMind(getMind() + 2);
    setCurrXP(getCurrXP() - getMaxXP());
    setMaxXP(getMaxXP() + 25);

    cout << "Your level is now " << getLevel() << "!" << endl;
  }
}

inline characterType stringToCharacterType(const string& str) {
  if (str == "PALADIN")
    return PALADIN;
  else if (str == "SUPERHERO")
    return SUPERHERO;
  else if (str == "ASSASSIN")
    return ASSASSIN;
  else if (str == "ASIANMOM")
    return ASIANMOM;
  else if (str == "CYBORG")
    return CYBORG;
  else if (str == "SNIPER")
    return SNIPER;
  else if (str == "WIZARD")
    return WIZARD;
  else if (str == "WEAKZOMBIE")
    return WEAKZOMBIE;
  else if (str == "STRONGZOMBIE")
    return STRONGZOMBIE;
  else
    return STRONGZOMBIE;
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
void Cyborg::CyborgToFile(string username) {
  if (!isCSV(username)) {
    username = username + ".csv";
  }
  ofstream file(username);
  file << this->name << '\n'
       << this->age << '\n'
       << this->role << '\n'
       << this->level << '\n'
       << this->coin << '\n'
       << this->currHP << '\n'
       << this->currXP << '\n'
       << this->maxHP << '\n'
       << this->maxXP << '\n'
       << this->attack << '\n'
       << this->defense << '\n'
       << this->stamina << '\n'
       << itemID(this->armor) << '\n'
       << itemID(this->weapon) << '\n'
       << this->strength << '\n'
       << this->endurance << '\n'
       << this->accuracy << '\n'
       << this->pace << '\n'
       << this->mind << '\n'
       << this->inventorySize() << '\n';
  if (this->inventorySize() > 0) {
    for (int i = 0; i < this->inventorySize(); i++) {
      file << inventory[i]->getID() << '\n' << inventory[i]->getCount() << '\n';
    }
  }
  ifstream users;
  users.open("usernames.csv");
  string name;
  string role;
  int check = 0;
  while (getline(users, name)) {
    getline(users, role);
    if (name == username && role == "Cyborg") {
      check++;
      break;
    }
  }
  if (check == 0) {
    ofstream usersfile("usernames.csv", ios::app);
    usersfile << username << '\n' << "Cyborg" << '\n';
  }
}
void Cyborg::FileToCyborg(string username) {
  if (!isCSV(username)) {
    username = username + ".csv";
  }
  ifstream file(username);
  if (file.good() && !std::filesystem::is_empty(username)) {
    string line;
    getline(file, line);
    this->name = line;
    getline(file, line);
    this->age = stoi(line);
    getline(file, line);
    this->role = stringToCharacterType(line);
    getline(file, line);
    this->level = stoi(line);
    getline(file, line);
    this->coin = stoi(line);
    getline(file, line);
    this->currHP = atof(line.c_str());
    getline(file, line);
    this->currXP = stoi(line);
    getline(file, line);
    this->maxHP = atof(line.c_str());
    getline(file, line);
    this->maxXP = stoi(line);
    getline(file, line);
    this->attack = atof(line.c_str());
    getline(file, line);
    this->defense = atof(line.c_str());
    getline(file, line);
    this->stamina = atof(line.c_str());
    getline(file, line);
    Human* human =
        new Cyborg("name", 1, 100.0, 3.0, 5.0, characterType::ASIANMOM, 1000);
    if (line == "-1") {
      this->armor = nullptr;
    } else {
      this->armor = ItemFactory::createItem(stoi(line), human, true);
      this->armor->setCount(1);
    }
    getline(file, line);
    if (line == "-1") {
      this->weapon = nullptr;
    } else {
      this->weapon = ItemFactory::createItem(stoi(line), human, true);
      this->weapon->setCount(1);
    }
    getline(file, line);
    this->strength = atof(line.c_str());
    getline(file, line);
    this->endurance = atof(line.c_str());
    getline(file, line);
    this->accuracy = atof(line.c_str());
    getline(file, line);
    this->pace = atof(line.c_str());
    getline(file, line);
    this->mind = atof(line.c_str());
    string inventorysize;
    getline(file, inventorysize);
    int n = stoi(inventorysize);
    if (n > 0) {
      for (int i = 0; i < n; i++) {
        string sID, scount;
        int count, ID;
        getline(file, sID);
        getline(file, scount);
        count = stoi(scount);
        ID = stoi(sID);
        Human* human = new Cyborg("name", 1, 100.0, 3.0, 5.0,
                                  characterType::ASIANMOM, 1000);
        Item* item = ItemFactory::createItem(ID, human, true);
        item->setCount(count);
        this->addInventory(item);
      }
    }
  } else {
    this->name = "Error404";
    this->age = 0;
  }
}
// double convertedPrice = atof(sprice.c_str());
// if (vip == "true")
// {
//   Item *item = new VIPItem(name, convertedPrice, count);
//   inventory.push_back(item);
// }
// else
// {
//   Item *item = new RegularItem(name, convertedPrice, count);
//   inventory.push_back(item);
// }
