#include "HumanEnemy.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Paladin.h"



HumanEnemy::HumanEnemy(int level, Human& humanRef) : Enemy(level), humanRef(humanRef) {
    srand(time(NULL));
    attackStrategy = new HumanEnemyAttack();
    
    hp = 2 * level + rand() % (5 * level / 4);
    attack = 4 * level + rand() % (5 * level / 4);
    defense = 2 * level + rand() % (5 * level / 4);
    level = abs(level - 4 + rand() % 6) + 1;
    giveExp = level * 10 * attack / defense;
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
    
    hp = 2 * level + rand() % (5 * level / 4);
    attack = 4 * level + rand() % (5 * level / 4);
    defense = 2 * level + rand() % (5 * level / 4);
    level = abs(level - 4 + rand() % 6) + 1;
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
    int role = rand() % 9;
    if (role == 7 || role == 8) {
        role = rand() % 9;
    }
    return static_cast<characterType>(role);
}

void HumanEnemy::setRoleBasedOnHuman(Human& human) {
    this->role = human.getRole();
}

void HumanEnemy::performAttack(Character& target) {
    if (attackStrategy) {
        double damage = attackStrategy->attackEnemy(&target, this);
        target.takeDamage(damage);
    } else {
        std::cout << getcharType() << " attacks " << target.getName() << " with a basic attack." << std::endl;
        target.takeDamage(getAttack());
    }
}

void HumanEnemy::performDefense(Human& attacker) {
    if (attackStrategy) {
        double damage = attackStrategy->defenseEnemy(&attacker, this);
        takeDamage(damage);
    } else {
        takeDamage(attacker.getAttack());
        std::cout << getcharType() << " defends against " << attacker.getName() << " with a basic defense." << std::endl;
    }
}
