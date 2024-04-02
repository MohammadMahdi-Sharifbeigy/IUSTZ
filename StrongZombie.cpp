#include "StrongZombie.h"
#include <cmath>
#include <cstdlib>

using namespace std;
StrongZombie::StrongZombie() {}

StrongZombie::StrongZombie(int level) : Enemy(level) {
  role = STRONGZOMBIE;
  srand(time(NULL));
  hp = 3 * level + rand() % (5 * level / 2) + 100 ; // Stronger health
  attack = 5 * level + rand() % (5 * level / 2); // Stronger attack
  defense = 3 * level + rand() % (5 * level / 2); // Stronger defense
  level = abs(level - 2 + rand() % 3) + 1; // Less variability in level
  giveExp = level * 15 * attack / defense; // More experience given
}
