#include "StrongZombie.h"
#include <cmath>
#include <cstdlib>

using namespace std;
StrongZombie::StrongZombie() {}

StrongZombie::StrongZombie(int level) : Enemy(level) {
  role = STRONGZOMBIE;
  srand(time(NULL));
  hp = 2 * level + rand() % (5 * level / 4);
  attack = 4 * level + rand() % (5 * level / 4);
  defense = 2 * level + rand() % (5 * level / 4);
  level = abs(level - 4 + rand() % 6) + 1;
  giveExp = level * 10 * attack / defense;
}

int StrongZombie::attackChar(double charDefense) {
  return abs((((((2 * level / 5) + 2) * (35 + (level * 9 / 10)) * attack) /
               charDefense) /
              50) +
             2);
}
