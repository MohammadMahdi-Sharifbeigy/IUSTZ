#include "StrongZombie.h"
#include <cstdlib>
#include <cmath>

StrongZombie::StrongZombie(){}

StrongZombie::StrongZombie(int level) : Enemy(level) {
    role = STRONGZOMBIE;
    std::srand(time(NULL));
    hp = 2 * level + std::rand() % (5 * level / 4);
    attack = 4 * level + std::rand() % (5 * level / 4);
    defense = 2 * level + std::rand() % (5 * level / 4);
    level = std::abs(level - 4 + std::rand() % 6) + 1;
    giveExp = level * 10 * attack / defense;
}

int StrongZombie::attackChar(double charDefense) {
    return std::abs((((((2 * level / 5) + 2) * (35 + (level * 9 / 10)) * attack) / charDefense) / 50) + 2);
}