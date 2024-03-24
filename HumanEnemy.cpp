#include "HumanEnemy.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

HumanEnemy::HumanEnemy(Human& humanRef) : humanRef(humanRef) {
    attackStrategy = new HumanEnemyAttack();
}

HumanEnemy::HumanEnemy(int level, Human& humanRef) : Enemy(level), humanRef(humanRef) {
    srand(time(NULL));
    attackStrategy = new HumanEnemyAttack();
    
    hp = 2 * level + rand() % (5 * level / 4);
    attack = 4 * level + rand() % (5 * level / 4);
    defense = 2 * level + rand() % (5 * level / 4);
    level = abs(level - 4 + rand() % 6) + 1;
    giveExp = level * 10 * attack / defense;
    role = getRandomRole();  // Set role randomly
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
