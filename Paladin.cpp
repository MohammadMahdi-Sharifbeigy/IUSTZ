#include "Paladin.h"
#include <fstream>
#include <iostream>
#include "AttackStrategy.h"
#include "Character.h"
#include "CharacterType.h"
#include "Human.h"

using namespace std;

Paladin::Paladin(const string& name,
                 int age,
                 double hp,
                 double defense,
                 double attack,
                 characterType role,
                 int coin)
    : Human(name, age, hp, attack, defense, role) {
  attackStrategy = new PaladinAttack();
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

Paladin::~Paladin() {
  delete attackStrategy;
}

void Paladin::performAttack(Character& target) {
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
      enemy->set_enemy_hp(Paladin::getAttack());
      // enemy->takeDamage(Paladin::getAttack());
    }
  }
}

void Paladin::performDefense(Character& attacker) {
  if (attackStrategy) {
    if (Enemy* enemy = dynamic_cast<Enemy*>(&attacker)) {
      double damage = attackStrategy->defenseEnemy(this, enemy);
      Paladin::currHP -= damage;
    }
  } else {
    Paladin::currHP -= Paladin::getDefense();
    cout << getName() << " defends against " << attacker.getcharType()
         << " with a basic defense." << endl;
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

void Paladin::PaladinToFile(string username) {
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
    if (name == username && role == "Paladin") {
      check++;
      break;
    }
  }
  if (check == 0) {
    ofstream usersfile("usernames.", ios::app);
    usersfile << username << '\n' << "Paladin" << '\n';
  }
}

void Paladin::FileToPaladin(string username) {
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
    // double price;
    getline(file, name);
    getline(file, scount);
    getline(file, vip);
    getline(file, sprice);
    count = stoi(scount);
    // double convertedPrice = atof(sprice.c_str());
    // if(vip == "true"){
    //     Item* item = Item(name,price,true,count );
    //     inventory.push_back(item);
    // }else{
    //     Item* item = Item(name,price,false,count );
    //     inventory.push_back(item);
    // }
  }
}
