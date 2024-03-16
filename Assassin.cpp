#include "Assassin.h"
#include "Character.h"
#include "AttackStrategy.h"
#include "Human.h"
#include "CharacterType.h"
#include "Enemy.h"
#include <iostream>

Assassin::Assassin(const std::string &name, double hp, double defense, double attack, characterType role)
    : Human(name, hp, attack, defense, role)
{
  attackStrategy = new AssassinAttack();
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

Assassin::~Assassin()
{
  delete attackStrategy;
}

void Assassin::performAttack(Character &target)
{
  if (attackStrategy)
  {
    if (Enemy *enemy = dynamic_cast<Enemy *>(&target))
    {
      attackStrategy->attackEnemy(this, enemy);
    }
  }
  else
  {
    std::cout << getName() << " attacks " << target.getName() << " with a basic attack." << std::endl;
  }
}

void Assassin::performDefense(Enemy &attacker)
{
  if (attackStrategy)
  {
    if (Enemy *enemy = dynamic_cast<Enemy *>(&attacker))
    {
      attackStrategy->defenseEnemy(this, enemy);
    }
  }
  else
  {
    std::cout << getName() << " defends against " << attacker.getcharType() << " with a basic defense." << std::endl;
  }
}

void Assassin::levelUp()
{
  while (getCurrentXP() >= getMaxXP())
  {
    std::cout << "You have leveled up!" << std::endl;
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

    std::cout << "Your level is now " << getLevel() << "!" << std::endl;
  }
}



    void Assasin::AssasinToFile(string username){
        string checktxt = username.substr(username.size() - 4, 4);
         if (checktxt != ".csv") {
             username = username + ".csv";
         }
        ofstream file(username);
        file << this->name << '\n' << this->age << '\n' << this->role << '\n' << this->level << '\n' << this->coin << '\n' << this->currHP << '\n' << this->currXP << '\n'<< this->maxHP << '\n' << this->maxXP << '\n' << this->attack << '\n' << this->defense << '\n' << this->stamin <<'\n'<< this->armor <<'\n'<< this->weapon<<'\n'<<this->strenght << '\n' << this->endurance << '\n'<< this->accuracy << '\n' << this->pace << '\n' << this->mind << '\n' << this->inventorySize()<<'\n';
        for(int i=0; i<this->inventorySize(); i++){
            file<<inventory[i]->getName()<<'\n'<<inventory[i]->getCount()<<'\n'<<inventory[i]->isVIP()<<'\n'<<inventory[i]->getPrice()<<'\n';
        }
        std::ifstream users;
        users.open("usernames.csv");
        string name;
        string role;
        int check=0;
        While(getline(users , name)){
            getline(users , role);
            if (name == username && role == "Assasin"){
                check++;
                break;
            }
        }
        if(check==0){
            ofstream usersfile("usernames." , ios::app);
            usersfile<<username<<'\n'<<"Assasin"<<'\n';
        }
    }
    
    
    void Assasin::FileToAssasin(string username){
        string checktxt = username.substr(username.size() - 4, 4);
         if (checktxt != ".csv") {
             username = username + ".csv";
         }
        ifstream file(username);
        getline(file , this->name);
        getline(file,this->age);
        getline(file , this->role);
        getline(file,this->level);
        getline(file , this->coin);
        getline(file,this->currHP);
        getline(file , this->currXP);
        getline(file,this->maxHP);
        getline(file , this->maxXP);
        getline(file,this->attack);
        getline(file , this->defence);
        getline(file,this->stamin);
        getline(file , this->armor);
        getline(file,this->weapon);
        getline(file,this->strenght);
        getline(file , this->endurance);
        getline(file,this->accuracy);
        getline(file , this->pace);
        getline(file,this->mind);
        strin inventorysize;
        getline(file,inventorysize);
        int n = stoi(inventorysize);
        for(int i=0; i<n; i++){
            string name,scount,vip,sprice;
            int count;
            double price;
            getline(file,name);
            getline(file , scount);
            getline(file,vip);
            getline(file,sprice);
            count = stoi(scount);
            price = atof(sprice);
            if(vip == "true"){
                Item* item = Item(name,price,true,count );
                inventory.push_back(item);
            }else{
                Item* item = Item(name,price,false,count );
                inventory.push_back(item);
            }
        }
           }
    
    

