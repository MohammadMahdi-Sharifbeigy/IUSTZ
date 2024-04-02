#include "HumanEnemy.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Paladin.h"

HumanEnemy::HumanEnemy(int level, Human& humanRef) : Enemy(level), humanRef(humanRef) {
    srand(time(NULL));
    attackStrategy = new HumanEnemyAttack();
    level = abs(level+ rand() % 4) + 1;
    int ran = (rand() % (5 * level / 4));
    hp = 2 * level + ran + 100;
    attack = 4 * level + ran;
    defense = 2 * level + ran;
    role = getRandomRole();  // Set role randomly
    Human* hum = new Paladin("name", 1, 100.0, 3.0, 5.0, characterType::PALADIN, 1000);
    int random = getRandomNumber(1,6);
    Item* armor = ItemFactory::createItem(random,hum,true);
    this->addInventory(armor);
    random =  getRandomNumber(8,19);
    Item* weapon = ItemFactory::createItem(random,hum,true);
    this->addInventory(weapon);
    random =  getRandomNumber(22,27);
    Item* throwable = ItemFactory::createItem(random,hum,true);
    this->addInventory(throwable,30);
    random =  getRandomNumber(30,31);
    Item* potion = ItemFactory::createItem(random,hum,true);
    this->addInventory(potion);
    Item* healingPotion = ItemFactory::createItem(29,hum,true);
    this->addInventory(healingPotion,2);
    
}

HumanEnemy::HumanEnemy(int level, Human& human, Human& humanRef) : Enemy(level), humanRef(humanRef) {
    attackStrategy = new HumanEnemyAttack();
    srand(time(NULL));
    level = abs(level+ rand() % 4) + 1;
    int ran = (rand() % (5 * level / 4));
    hp = 2 * level + ran + 100;
    attack = 4 * level + ran;
    defense = 2 * level + ran;
    giveExp = level * 10 * attack / defense;
    setRoleBasedOnHuman(human);  // Set role based on the Human it is fighting
    Human* hum = new Paladin("name", 1, 100.0, 3.0, 5.0, characterType::PALADIN, 1000);
    int random = getRandomNumber(1,6);
    Item* armor = ItemFactory::createItem(random,hum,true);
    this->addInventory(armor);
    random =  getRandomNumber(8,19);
    Item* weapon = ItemFactory::createItem(random,hum,true);
    this->addInventory(weapon);
    random =  getRandomNumber(22,27);
    Item* throwable = ItemFactory::createItem(random,hum,true);
    this->addInventory(throwable,30);
    random =  getRandomNumber(30,31);
    Item* potion = ItemFactory::createItem(random,hum,true);
    this->addInventory(potion);
    Item* healingPotion = ItemFactory::createItem(29,hum,true);
    this->addInventory(healingPotion,2);
}

HumanEnemy::~HumanEnemy() {
    delete attackStrategy;
}

characterType HumanEnemy::getRandomRole() {
    int role = rand() % 10;
    if (role == 7 || role == 8 || role == 9) {
        role = rand() % 9;
    }
    return static_cast<characterType>(role);
}

void HumanEnemy::setRoleBasedOnHuman(Human& human) {
    this->role = human.getRole();
}

void HumanEnemy::performAttack(Character& target) {
    if (attackStrategy) {
        // Get the character type of 'this' HumanEnemy
        characterType currHumanRole = this->getRole();
        // Apply the FSM to get modified attack and defense values
        std::pair<double, double> modifiedValues = static_cast<HumanEnemyAttack*>(attackStrategy)->applyFSM(currHumanRole, &target, this);
        double modifiedAttack = modifiedValues.first;
        // Use the modified attack value to deal damage
        target.takeDamage(modifiedAttack);
    } else {
        std::cout << getcharType() << " attacks " << target.getName() << " with a basic attack." << std::endl;
        target.takeDamage(getAttack());
    }
}

void HumanEnemy::performDefense(Human& attacker) {
    if (attackStrategy) {
        // Get the character type of 'this' HumanEnemy
        characterType currHumanRole = this->getRole();
        // Apply the FSM to get modified attack and defense values
        std::pair<double, double> modifiedValues = static_cast<HumanEnemyAttack*>(attackStrategy)->applyFSM(currHumanRole, &attacker, this);
        double modifiedDefense = modifiedValues.second;
        // Use the modified defense value to reduce damage taken
        takeDamage(modifiedDefense);
    } else {
        std::cout << getcharType() << " defends against " << attacker.getName() << " with a basic defense." << std::endl;
        takeDamage(attacker.getAttack());
    }
}


void HumanEnemy::Update(Character& target) {
    switch (state) {
        case ATTACK:
            performAttack(target);
            if (hp <= 50) {
                state = DEFENSE;
            }
            break;
        case DEFENSE:
            Human* humanTarget = dynamic_cast<Human*>(&target);
            performDefense(*humanTarget);
            if (hp > 50) {
                state = ATTACK;
            }
            break;
        }
}