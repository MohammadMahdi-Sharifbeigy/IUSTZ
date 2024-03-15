#include "HumanEnemy.h"
#include "cmath"

HumanEnemy::HumanEnemy(){}

HumanEnemy::HumanEnemy(int level) : Enemy(level)
{
    std::srand(time(NULL));
    hp = 2 * level + rand() % (5 * level / 4);
    attack = 4 * level + rand() % (5 * level / 4);
    defense = 2 * level + rand() % (5 * level / 4);
    level = abs(level - 4 + rand() % 6) + 1;
    giveExp = level * 10 * attack / defense;
    role = getRandomRole(); // Set role randomly
}

HumanEnemy::HumanEnemy(int level, Human &human) : Enemy(level)
{
    std::srand(time(NULL));
    hp = 2 * level + rand() % (5 * level / 4);
    attack = 4 * level + rand() % (5 * level / 4);
    defense = 2 * level + rand() % (5 * level / 4);
    level = abs(level - 4 + rand() % 6) + 1;
    giveExp = level * 10 * attack / defense;
    setRoleBasedOnHuman(human); // Set role based on the Human it is fighting
}

// Function to generate a random characterType
characterType HumanEnemy::getRandomRole()
{
    int role = rand() % 8;
    if (role == 7 || role == 6)
    {
        role = rand() % 8;
    }
    return static_cast<characterType>(role);
}

// Function to set role based on the Human it is fighting
void HumanEnemy::setRoleBasedOnHuman(Human &human)
{
    this->role = human.getRole();
}

int HumanEnemy::attackChar(double charDefense)
{
    return abs((((((2 * level / 3) + 2) * (40 + (level * 9 / 10)) * attack) / charDefense) / 50) + 2);
}