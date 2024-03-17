#include "Cyborg.h"
#include <fstream>
#include <iostream>
#include <string>
#include "AttackStrategy.h"
#include "Character.h"
#include "CharacterType.h"
#include "Human.h"

using namespace std;

Cyborg::Cyborg(const string& name,
               int age,
               double hp,
               double defense,
               double attack,
               characterType role)
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
  coin = 0;
}

Cyborg::~Cyborg() {
  delete attackStrategy;
}

void Cyborg::performAttack(Character& target) {
  if (attackStrategy) {
    Enemy* enemy = dynamic_cast<Enemy*>(&target);
    if (enemy) {
        attackStrategy->attackEnemy(this,enemy);
    }
  } else {
    cout << getName() << " attacks " << target.getName()
              << " with a basic attack." << endl;
  }
}

void Cyborg::performDefense(Character& attacker) {
  if (attackStrategy) {
    if (Enemy* enemy = dynamic_cast<Enemy*>(&attacker)) {
      double damage = attackStrategy->defenseEnemy(this, enemy);
      Cyborg::currHP -= damage;    }
  } else {
    Cyborg::currHP -= Cyborg::getDefense();
    cout << getName() << " defends against " << attacker.getcharType()
              << " with a basic defense." << endl;
  }
}

void Cyborg::levelUp() {
  while (getCurrentXP() >= getMaxXP()) {
    cout << "You have leveled up!" << endl;
    setMaxHP(getMaxHP() + 30);
    setAttack(getAttack() + 10);
    setDefense(getDefense() + 5);
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

void Cyborg::CyborgToFile(string username) {
  string checktxt = username.substr(username.size() - 4, 4);
  if (checktxt != ".csv") {
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
       << this->armor << '\n'
       << this->weapon << '\n'
       << this->strength << '\n'
       << this->endurance << '\n'
       << this->accuracy << '\n'
       << this->pace << '\n'
       << this->mind << '\n'
       << this->inventorySize() << '\n';
  for (int i = 0; i < this->inventorySize(); i++) {
    file << inventory[i]->getName() << '\n'
         << inventory[i]->getCount() << '\n'
         << inventory[i]->isVIP() << '\n'
         << inventory[i]->getPrice() << '\n';
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
    ofstream usersfile("usernames.", ios::app);
    usersfile << username << '\n' << "Cyborg" << '\n';
  }
}
void Cyborg::FileToCyborg(string username) {
  string checktxt = username.substr(username.size() - 4, 4);
  if (checktxt != ".csv") {
    username = username + ".csv";
  }
  ifstream file(username);
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
  this->attack = atof(line.c_str());
  getline(file, line);
  this->defense = atof(line.c_str());
  getline(file, line);
  this->stamina = atof(line.c_str());
  // getline(file, line);
  // this->armor = stringToItem(line);
  // getline(file,line );
  // this->weapon = stringToItem(line);
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
  for (int i = 0; i < n; i++) {
    string name, scount, vip, sprice;
    int count;
    getline(file, name);
    getline(file, scount);
    getline(file, vip);
    getline(file, sprice);
    count = stoi(scount);
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
  }
}
